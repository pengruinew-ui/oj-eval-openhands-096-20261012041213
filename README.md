# Problem 096 - 二叉树的堂姐妹堂兄弟

**ACMOJ Problem ID**: 2444

## Table of Contents

- [Problem 096 - 二叉树的堂姐妹堂兄弟](#problem-096-二叉树的堂姐妹堂兄弟)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **2444. 二叉树的堂姐妹堂兄弟** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/096/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

在二叉树中，根节点的深度是  `0`，每个深度为 `k` 的节点的子节点位于深度 `k+1` 处。如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂姐妹堂兄弟节点。给定一个二叉树的前序遍历，空结点用 `-1` 补齐（即扩展二叉树）。给定两个节点 `x` 和 `y`，当他们是堂姐妹堂兄弟节点时，返回 `1`。否则，返回 `0`。二叉树的节点值不重复。

### Input Format

第一行是查询的个数。

第二行开始，每行代表查询的两个数。

最后一行是扩展二叉树前序遍历的结果。

### Output Format

每行代表一个查询的结果。

### Samples

#### Sample 1

**Input:**
```
2
6 5
3 7
2 6 -1 7 -1 -1 5 3 -1 4 -1 -1 1 -1 -1
```

**Output:**
```
0
1
```

### Data Constraints

对于 70% 的数据，整棵树最多有 200 个节点。

对于 100% 的数据，整棵树最多有 1000 个节点。

结点值的范围为 $1 \leq n \leq 1000$ 。

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 244 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/096/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
