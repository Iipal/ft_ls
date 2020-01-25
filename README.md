# ft_ls

#### Implementation of MacOS(Darwin) system command - `ls`, on C. [[education project](https://unit.ua/en/)]

## Additional info:

This project compiles using `clang`-compiler.

I also use submodules with SSH-key. For clone this project - be sure you are added SSH-key to your GitHub-profile and use this command:
```bash
git clone --recurse-submodules
```

## Install\Compile project makefile rules:
| Rule                 | Description                                                                                  |
| -------------------- | -------------------------------------------------------------------------------------------- |
| make                 | Compile libs and executable                                                                  |
| pre                  | Re-compile only executable source files                                                      |
| debug[_all]          | Compile with `-g3` only                                                                      |
| sanitize[_all]       | Compile with the same rules as `make debug` but adding `-fsanitize=address`                  |
| debug_assembly[_all] | Compile with the rules as `make debug` but adding `-S -masm=intel`                           |
| assembly[_all]       | Compile with default optimization rules but adding `-S -masm=intel` instead of `-flto -fpic` |
| re                   | Re-compile all libs and executable source files                                              |
| clean                | Delete all libs and executable .o files                                                      |
| fclean               | Same as `make clean` but also delete libs .a and executable files                            |
##### *[_all] means exist two versions of the rule: `*rule*` and `*rule*_all`. The second one - for the re-build whole project via depended on make-rule compiler flags, when first one - only for compile changed files with specific flags.

## Usage:
```bash
usage: ./ft_ls [-GRSTafglrtu1] [file ...]
```

### Flags:
| Flag | Description                                                                                  |
| ---- | -------------------------------------------------------------------------------------------- |
| -1   | Force output to be one entry per line. This is the default when output is not to a terminal. |
| -a   | Include directory entries whose names begin with a dot '.'.                                  |
| -f   | Output is not sorted. This option implies -a.                                                |
| -g   | List in long format as in -l, except that the owner is not printed.                          |
| -l   | List in long format.                                                                         |
| -R   | Recursively list subdirectories encountered.                                                 |
| -r   | Reverse order while sorting.                                                                 |
| -S   | Sort files by size.                                                                          |
| -T   | Display complete time information for the file.                                              |
| -t   | Sort by modification time, newest first.                                                     |
| -u   | Use file's last access time instead of last modification time for sorting (-t) or printing.  |
