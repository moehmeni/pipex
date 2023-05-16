# pipex
Playing with linux piping API

# Installation
```
make bonus
```

# Examples
```
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Should behave like this in shell
```
< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
here_doc is supported as well:
```
./pipex here_doc LIMITER cmd cmd1 file
```
Should behave like:
```
cmd << LIMITER | cmd1 >> file
```