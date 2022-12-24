function selectionSort(inputArr, desc) {
  const compareFn = desc ? (a, b) => a < b : (a, b) => a > b;
  let n = inputArr.length;
  let order = document.getElementById("order").value;
  for (let i = 0; i < n; i++) {
    let min = i;
    for (let j = i + 1; j < n; j++) {
      if (compareFn(inputArr[min], inputArr[j])) {
        min = j;
      }
    }
    if (min != i) {
      let tmp = inputArr[i];
      inputArr[i] = inputArr[min];
      inputArr[min] = tmp;
    }
  }
  return inputArr;
}
console.log(selectionSort([12, 1230, 0, 12, 23], true));
function partition(arr, start, end) {
  const pivotValue = arr[end];
  let pivotIndex = start;
  let order = document.getElementById("order").value;

  if (order === "asc") {
    for (let i = start; i < end; i++) {
      if (arr[i] < pivotValue) {
        [arr[i], arr[pivotIndex]] = [arr[pivotIndex], arr[i]];
        pivotIndex++;
      }
    }
  } else {
    for (let i = start; i < end; i++) {
      if (arr[i] > pivotValue) {
        [arr[i], arr[pivotIndex]] = [arr[pivotIndex], arr[i]];

        pivotIndex++;
      }
    }
  }

  [arr[pivotIndex], arr[end]] = [arr[end], arr[pivotIndex]];
  return pivotIndex;
}

function quickSort(arr, start, end) {
  if (start >= end) {
    return;
  }

  let index = partition(arr, start, end);

  quickSort(arr, start, index - 1);
  quickSort(arr, index + 1, end);
}

document.getElementById("submit").addEventListener("click", (e) => {
  let data = document.getElementById("input").value.split(",");
  let type = document.getElementById("type").value;
  let way = document.getElementById("way").value;
  let order = document.getElementById("order").value;

  if (type === "number") {
    data = data.map((ele) => Number(ele));
  }
  if (way === "S") {
    selectionSort(data, order === "desc");
  } else {
    quickSort(data, 0, data.length - 1);
  }
  console.log(data);

  document.getElementById("ans").innerHTML = data.toString();
});
function wordFrequencyCounter() {
  let str = document.getElementById("stext").value;
  let str1 = str.split(" ");
  str1 = str1.map((s) => s.toLowerCase());
  let obj = {};
  for (let i = 0; i < str1.length; i++) {
    if (obj[str1[i]]) {
      obj[str1[i]]++;
    } else {
      obj[str1[i]] = 1;
    }
  }
  console.log(obj);
  let str2 = "";
  for (let key in obj) {
    str2 += key + ": " + obj[key] + "<br>";
  }
  document.getElementById("result").innerHTML = str2;
}
const stopwords = [
  "a",
  "about",
  "above",
  "after",
  "again",
  "against",
  "all",
  "am",
  "an",
  "and",
  "any",
  "are",
  "aren't",
  "as",
  "at",
  "be",
  "because",
  "been",
  "before",
  "being",
  "beleft",
  "between",
  "both",
  "but",
  "by",
  "can't",
  "cannot",
  "could",
  "couldn't",
  "did",
  "didn't",
  "do",
  "does",
  "doesn't",
  "doing",
  "don't",
  "down",
  "during",
  "each",
  "few",
  "for",
  "from",
  "further",
  "had",
  "hadn't",
  "has",
  "hasn't",
  "have",
  "haven't",
  "having",
  "he",
  "he'd",
  "he'll",
  "he's",
  "her",
  "here",
  "here's",
  "hers",
  "herself",
  "him",
  "himself",
  "his",
  "how",
  "how's",
  "i",
  "i'd",
  "i'll",
  "i'm",
  "i've",
  "if",
  "in",
  "into",
  "is",
  "isn't",
  "it",
  "it's",
  "its",
  "itself",
  "let's",
  "me",
  "more",
  "most",
  "mustn't",
  "my",
  "myself",
  "no",
  "nor",
  "not",
  "of",
  "off",
  "on",
  "once",
  "only",
  "or",
  "other",
  "ought",
  "our",
  "ours",
  "ourselves",
  "out",
  "over",
  "own",
  "same",
  "shan't",
  "she",
  "she'd",
  "she'll",
  "she's",
  "should",
  "shouldn't",
  "so",
  "some",
  "such",
  "than",
  "that",
  "that's",
  "the",
  "their",
  "theirs",
  "them",
  "themselves",
  "then",
  "there",
  "there's",
  "these",
  "they",
  "they'd",
  "they'll",
  "they're",
  "they've",
  "this",
  "those",
  "through",
  "to",
  "too",
  "under",
  "until",
  "up",
  "very",
  "was",
  "wasn't",
  "we",
  "we'd",
  "we'll",
  "we're",
  "we've",
  "were",
  "weren't",
  "what",
  "what's",
  "when",
  "when's",
  "where",
  "where's",
  "which",
  "while",
  "who",
  "who's",
  "whom",
  "why",
  "why's",
  "with",
  "won't",
  "would",
  "wouldn't",
  "you",
  "you'd",
  "you'll",
  "you're",
  "you've",
  "your",
  "yours",
  "yourself",
  "yourselves",
];

function removeStopWords(inputText) {
  let regex = /[.,]/g;
  inputText = inputText.replace(regex, "");
  let textArray = inputText.split(" ");
  let finalStringArray = [];
  for (let i = 0; i < textArray.length; i++) {
    if (!stopwords.includes(textArray[i])) {
      finalStringArray.push(textArray[i]);
    }
  }
  let finalString = finalStringArray.join(" ");
  return finalString;
}

document.getElementById("button3a").addEventListener("click", function () {
  let inputText = document.getElementById("text3a").value;

  let finalString = removeStopWords(inputText);

  document.getElementById("output3a").value = finalString;
});
