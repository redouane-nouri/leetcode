function longestCommonPrefix(strs: string[]): string {
  let prefix = strs[0];

  for (let i = 1; i < strs.length; i++) {
    let j = 0;

    while (
      j < prefix.length &&
      j < strs[i].length &&
      prefix[j] === strs[i][j]
    ) {
      j++;
    }

    if (prefix.length > j) {
      prefix = prefix.slice(0, j);
    }
  }

  return prefix;
}
