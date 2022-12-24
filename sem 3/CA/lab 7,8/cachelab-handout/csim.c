/*
Name:-Satya venkata kiran patnala
Roll no.:-S20200010169
*/
#include <assert.h>
#include <errno.h>
#include <getopt.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cachelab.h"

#define ADDRESS_LENGTH 64

#define pow(two, shift) (1 << (shift))

typedef unsigned long long int mem_addr_t;

typedef struct cache_line {
    char valid;
    mem_addr_t tag;
    unsigned long long int lru;
} cache_line_t;

typedef cache_line_t* cache_set_t;
typedef cache_set_t* cache_t;

int verbosity = 0; 
int s = 0;        
int b = 0;         
int E = 0;         
char* trace_file = NULL;

int S; 
int B; 

int miss_count = 0;
int hit_count = 0;
int eviction_count = 0;
unsigned long long int lru_counter = 1;

cache_t cache;
mem_addr_t set_index_mask;


void initCache() {
    int i, j;
    cache = (cache_set_t*)malloc(sizeof(cache_set_t) * S);
    for (i = 0; i < S; i++) {
        cache[i] = (cache_line_t*)malloc(sizeof(cache_line_t) * E);
        for (j = 0; j < E; j++) {
            cache[i][j].valid = 0;
            cache[i][j].tag = 0;
            cache[i][j].lru = 0;
        }
    }

    set_index_mask = (mem_addr_t)(pow(2, s) - 1);
}


void freeCache() {
    int i;
    for (i = 0; i < S; i++) {
        free(cache[i]);
    }
    free(cache);
}


void accessData(mem_addr_t addr) {
    int i;
    unsigned long long int eviction_lru = ULONG_MAX;
    unsigned int eviction_line = 0;
    mem_addr_t set_index = (addr >> b) & set_index_mask;
    mem_addr_t tag = addr >> (s + b);

    cache_set_t cache_set = cache[set_index];

    for (i = 0; i < E; ++i) {
        if (cache_set[i].valid) {
            if (cache_set[i].tag == tag) {
                cache_set[i].lru = lru_counter++;
                hit_count++;
                return;
            }
        }
    }

    miss_count++;

    for (int i = 0; i < E; ++i) {
        if (eviction_lru > cache_set[i].lru) {
            eviction_line = i;
            eviction_lru = cache_set[i].lru;
        }
    }

    if (cache_set[eviction_line].valid) {
        eviction_count++;
    }

    cache_set[eviction_line].valid = 1;
    cache_set[eviction_line].tag = tag;
    cache_set[eviction_line].lru = lru_counter++;
}


void replayTrace(char* trace_fn) {
    FILE* trace_fp = fopen(trace_fn, "r");
    char trace_cmd;
    mem_addr_t address;
    int size;

    while (fscanf(trace_fp, " %c %llx,%d", &trace_cmd, &address, &size) == 3) {
        switch(trace_cmd) {
            case 'L': accessData(address); break;
            case 'S': accessData(address); break;
            case 'M': accessData(address); accessData(address); break;
            default: break;
        }
    }

    fclose(trace_fp);
}


void printUsage(char* argv[]) {
    printf("Usage: %s [-hv] -s <num> -E <num> -b <num> -t <file>\n", argv[0]);
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("\nExamples:\n");
    printf("  linux>  %s -s 4 -E 1 -b 4 -t traces/yi.trace\n", argv[0]);
    printf("  linux>  %s -v -s 8 -E 2 -b 4 -t traces/yi.trace\n", argv[0]);
    exit(0);
}

int main(int argc, char* argv[]) {
    char c;

    while ((c = getopt(argc, argv, "s:E:b:t:vh")) != -1) {
        switch (c) {
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                trace_file = optarg;
                break;
            case 'v':
                verbosity = 1;
                break;
            case 'h':
                printUsage(argv);
                exit(0);
            default:
                printUsage(argv);
                exit(1);
        }
    }

    if (s == 0 || E == 0 || b == 0 || trace_file == NULL) {
        printf("%s: Missing required command line argument\n", argv[0]);
        printUsage(argv);
        exit(1);
    }

    S = (unsigned int)pow(2, s);
    B = (unsigned int)pow(2, b);

    initCache();

#ifdef DEBUG_ON
    printf("DEBUG: S:%u E:%u B:%u trace:%s\n", S, E, B, trace_file);
    printf("DEBUG: set_index_mask: %llu\n", set_index_mask);
#endif

    replayTrace(trace_file);

    freeCache();

    printSummary(hit_count, miss_count, eviction_count);
    return 0;
}