[Tutorial link](https://makefiletutorial.com/#pattern-rules)

#### A Makefile consists of a set of rules. A rule generally looks like this:
<br>

```Makefile
  targets: prerequisites
    command
    command
    command
```

 - The targets are file names, seperated by spaces. Typically, there is only one per rule.

 - The commands are a series of steps typically used to make the target(s). These need to start with a tab character, not spaces.

 - The prerequisites are also file names, seperated by spaces. These files need to exist before the commands for the target are run. These are also called dependencies
  