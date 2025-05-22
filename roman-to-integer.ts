const roman_to_int_map = new Map<string, number>([
  ["I", 1],
  ["V", 5],
  ["X", 10],
  ["L", 50],
  ["C", 100],
  ["D", 500],
  ["M", 1000],
]);

function romanToInt(s: string): number {
  let result = 0;

  for (let i = 0; i < s.length; i++) {
    if (
      i + 1 !== s.length &&
      roman_to_int_map.get(s[i])! < roman_to_int_map.get(s[i + 1])!
    ) {
      result -= roman_to_int_map.get(s[i])!;
    } else {
      result += roman_to_int_map.get(s[i])!;
    }
  }

  return result;
}
