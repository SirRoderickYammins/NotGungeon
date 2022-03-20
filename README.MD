# RaylibCGame

This is a game written in pure C using the Raylib framework. It's more of a test game for me to learn, and I may end up finishing it.

## Installation

For any platform, make sure you clone this repository somewhere on your computer.

### Windows

You'll need mingw32 and gcc (the compiler for C).

Clone the raylib library from [its git page](https://github.com/raysan5/raylib)

Follow the instructions for compiling under Windows. Once complete, copy the "libraylib.a" file from the src folder in raylib into the `lib/raylib` folder in my project.

Next, all you need to do is hop into the `src` folder in my project and type

```
mingw32-make dirs

mingw32-make game
```

The compiled game binary will be in the `bin` folder.

### Linux and MacOS

The above steps are exactly the same, except that you will not use mingw32. Instead, make and gcc (or cc for Mac) should already be installed.

Therefore, just remove the `mingw32-` part of each command and replicate the above instructions.
