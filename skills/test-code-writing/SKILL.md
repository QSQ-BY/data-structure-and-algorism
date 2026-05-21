---
name: test-code-writing
description: Write or update test code in the user's algorithm/data-structure exercises using the user's preferred style. Use when the user asks for "/测试代码编写", "测试代码编写", or asks to add tests for an algorithm/function while keeping changes scoped: put tests inside the existing test function when requested, use multiple cases, and format console output neatly, preferably as a table.
---

# /测试代码编写

Follow this workflow when adding test code for the user's algorithm exercises.

## Core Rules

- Respect the user's requested edit scope exactly. If they say only edit `test01()`, do not change includes, solution logic, `main()`, or unrelated files.
- Read the target file first and match its C++ style, naming, and existing output habits.
- Put test logic in the existing test function unless the user asks otherwise.
- Use multiple cases. Default to at least 3; prefer 5 when there are common edge cases and examples.
- Include both positive and negative cases when the function returns a boolean or classification result.
- Make console output clean, aligned, and easy to scan. Prefer an ASCII table.
- Keep dependencies minimal. If the user forbids touching includes or the edit scope excludes includes, use tools already available, such as `cout.width()` instead of adding `<iomanip>`.
- Verify by compiling and running when feasible. If verification cannot run, state the reason briefly.

## Table Output Pattern

For C++ console tests, prefer this shape:

```cpp
cout << boolalpha;
cout << "+------+--------+----------+----------+" << endl;
cout << "| Case | Input  | Expected | Actual   |" << endl;
cout << "+------+--------+----------+----------+" << endl;

for (int i = 0; i < caseCount; i++) {
    bool actual = s.someFunction(inputs[i]);

    cout << "| ";
    cout.width(4);
    cout << left << i + 1 << " | ";
    cout.width(6);
    cout << left << inputs[i] << " | ";
    cout.width(8);
    cout << left << expected[i] << " | ";
    cout.width(8);
    cout << left << actual << " |" << endl;
}

cout << "+------+--------+----------+----------+" << endl;
```

Adjust column names and widths to fit the algorithm. Add useful diagnostic columns when the solution exposes helper methods, such as cycle entry, output list, or length.

## Case Selection

- Include official examples from the problem statement when available.
- Add boundary or simple cases such as empty input, single element, `1`, `0`, or minimal valid input when relevant.
- Add representative normal cases.
- Add failure or false cases when relevant.

## Response Style

After editing, summarize the changed test function and mention the verification command/result. Keep the final response concise.
