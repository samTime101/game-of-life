# Game Of Life
Implemented in C using [Raylib](https://github.com/raysan5/raylib)

> [!CAUTION]
> The codes in any of the `folders` are not properly formatted  and are from `2 years ago`,

> [!TIP]
> The best one is `main.c` which you can compile and run

### Compilatiom
```make
make:
	gcc main.c -o main ./lib/libraylib.a -I ./include -lGL -lm -ldl -lpthread
```

### Preview of `main.c` (latest)
[Screencast from 02-07-2025 08:02:17 PM.webm](https://github.com/user-attachments/assets/7298c734-bc4e-4e0b-b9ca-98eb17b48526)



# Controls
  ```-esc            :  Terminate Window
     -rightclick     :  Add a live cell
     -Space          : Start or pause simulation 
  ```

# Some Renders (old)
![](https://github.com/samTime101/game-of-life/blob/main/renders/try%20render%202023-12-04%2012-11-46.gif)
<br>
![](https://github.com/samTime101/game-of-life/blob/main/renders/Screenshot%202023-12-04%20121436.png)
