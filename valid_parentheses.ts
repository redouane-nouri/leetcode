const open_brackets_set = new Set(["(", "{", "["]);
const open_to_close_brackets_map = new Map<string, string>([
  ["(", ")"],
  ["{", "}"],
  ["[", "]"],
]);

function isValid(s: string): boolean {
  const open_brackets: string[] = [];
  let last_opened_bracket: string | undefined = undefined;

  for (const char of s) {
    if (open_brackets_set.has(char)) {
      open_brackets.push(char);
    } else {
      if (
        !open_brackets.length ||
        !(open_to_close_brackets_map.get(open_brackets.pop()!) === char)
      ) {
        return false;
      }
    }
  }

  return open_brackets.length === 0;
}
