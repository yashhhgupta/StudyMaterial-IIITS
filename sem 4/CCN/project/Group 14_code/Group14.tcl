set ns [new Simulator]

$ns rtproto DV

$ns color 1 Blue
$ns color 2 Red

set nf [open out.nam w]
$ns namtrace-all $nf

set nt [open 14_pract.tr w]
$ns trace-all $nt

proc finish {} {
    global ns nf
    $ns flush-trace
    close $nf
    exec nam out.nam &
    exec awk -f 14_throughput.awk 14_pract.tr &
    exec awk -f 14_delay.awk 14_pract.tr &
    exec awk -f 14_packet_delivery.awk 14_pract.tr &
    exit 0
}

set n0 [$ns node]
# set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]

#Create links between the nodes
# $ns duplex-link $n0 $n1 2Mb 10ms DropTail
# $ns duplex-link $n1 $n2 4.2Mb 10ms DropTail
$ns duplex-link $n0 $n3 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 2.2Mb 20ms DropTail
$ns duplex-link $n3 $n4 2Mb 10ms DropTail
$ns duplex-link $n4 $n5 2Mb 10ms DropTail
$ns duplex-link $n5 $n6 1.7Mb 20ms DropTail
$ns duplex-link $n6 $n7 2Mb 10ms DropTail
$ns duplex-link $n5 $n8 2Mb 10ms DropTail
$ns duplex-link $n7 $n8 2Mb 10ms DropTail
$ns duplex-link $n8 $n0 1.7Mb 20ms DropTail

#Set Queue Size of link (n2-n3) to 10
$ns queue-limit $n2 $n3 10


$ns duplex-link-op $n2 $n3 queuePos 0.5


set tcp0 [new Agent/TCP]
$tcp0 set class_ 2
$ns attach-agent $n0 $tcp0
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp0 $sink
$tcp0 set fid 1



set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set type FTP
$ftp0 set packetsize 2000
$ftp0 set rate_ 1mb



$ns at 0.5 "$ftp0 start"
# $ns rtmodel-at 2.0 down $n0 $n1
# $ns rtmodel-at 4.0 up $n0 $n1
# $ns rtmodel-at 2.0 down $n2 $n3
# $ns rtmodel-at 5.0 up $n2 $n3
# $ns rtmodel-at 3.5 down $n0 $n8
# $ns rtmodel-at 5.5 up $n0 $n8



$ns at 6.0 "finish"

$ns run
