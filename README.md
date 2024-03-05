
#  Obj_Orient_Pool

The command line I used for formatting my code, given the strict limitations we have at 42 regarding packages..
```sh
docker run -it --rm -v $(pwd):/workdir -w /workdir snowstep/llvm clang-format -i -style=microsoft [FILE].cpp
```

 - **docker run**: Initiates a new Docker container.
 - **-it**: Ensures that the container runs in interactive mode.
 - **--rm**: Removes the container after its execution.
 - **-v $(pwd):/workdir**: Maps the current directory on the host system to the /workdir directory within the container. This allows the container to access files on your host system.
 - **-w /workdir**: Sets the working directory to /workdir.
 - **snowstep/llvm**: Debian/Ubuntu with the latest LLVM installed.
 - **clang-format -i [FILE].cpp**: Executes clang-format on [FILE].cpp
   to format it. The -i option modifies the file directly.
- **-style=microsoft**: The formatting code style.