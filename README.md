# ft_ls

#### Implementation of MacOS(Darwin) system utilite - `ls`, on C. (project from school42([UNIT Factory](https://unit.ua/en/)))

## Install\Compile project makefile rules:

This project compile using `clang`-compiler.

Also used submodules. For clone use
```bash
git clone --recurse-submodules
```
and add SSH-key to your github profile.

| Rule             | Description                                                                 |
| ---------------- | --------------------------------------------------------------------------- |
| $> make          | Compile libs and executable                                                 |
| $> make pre      | Re-compile only executable source files                                     |
| $> make debug    | Compile with `-glldb -D DEBUG`                                              |
| $> make sanitize | Compile with the same rules as `make debug` but adding `-fsanitize=address` |
| $> make re       | Re-compile all libs and executable source files                             |
| $> make clean    | Delete all libs and executable .o files                                     |
| $> make fclean   | Same as `make clean` but also delete libs .a and executable files           |
| $> make norme    | Only for MacOS in school42                                                  |

## Usage:
```bash
usage: ./ft_ls [-GRSTafglrtu1] [file ...]
```

### Flags:
| Flag | Description                                                                                   |
| ---- | --------------------------------------------------------------------------------------------- |
| -1   | Forece output to be one entry per line. This is the default when output is not to a terminal. |
| -a   | Include directory entries whose names begin with a dot '.'.                                   |
| -f   | Output is not sorted. This option implies -a.                                                 |
| -g   | List in long format as in -l, except that the owner is not printed.                           |
| -l   | List in long format.                                                                          |
| -R   | Recursively list subdirectories encountered.                                                  |
| -r   | Reverse order while sorting.                                                                  |
| -S   | Sort files by size.                                                                           |
| -T   | Display complete time information for the file.                                               |
| -t   | Sort by modification time, newest first.                                                      |
| -u   | Use file's last access time instead of last modification time for sorting (-t) or printing.   |
