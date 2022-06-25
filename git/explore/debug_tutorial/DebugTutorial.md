[ref link](https://code.visualstudio.com/docs/cpp/config-linux)

## Files
You'll create the following three files in the .vscode folder:
1. tasks.json (compiler build settings)
2. launch.json (debugger settings)
3. c_cpp_properties.json (compiler path and IntelliSense settings)

## Hello World
You'll write a simple program to loop through a vector of strings and print each one. It's called `helloworld.cc`.

## Debugger
You'll select **g++ build and debug active file** the first time you run `helloworld.cc`. That will cause the g++ compiler to be set as the default compiler each time the program is run in the future. VS Code creates the `tasks.json` file in the `.vscode` folder in this workspace, which enables this default to be set and carried out each time the program is run.

You can now use the debugger to run with breakpoints and step through the execution steps, examining variables along the way.