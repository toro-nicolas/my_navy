# my_navy

### Table of contents
- [Project goal](https://github.com/toro-nicolas/my_navy#project-goal)
- [How to compile it ?](https://github.com/toro-nicolas/my_navy#how-to-compile-it-)
- [How to use it ?](https://github.com/toro-nicolas/my_navy#how-to-use-it-)
- [How to create a valid map ?](https://github.com/toro-nicolas/my_navy#how-to-create-a-valid-map-)
- [Final result on my.epitech.eu](https://github.com/toro-nicolas/my_navy#final-result-on-my.epitech.eu)

### Project goal
Reproduction of a naval battle game in C.    
The program uses signals (SIGUSR1 and SIGUSR2) and the TCP protocol to communicate between players.

### How to compile it ?
Make the game :
```shell
make
```

Re make the game :
```shell
# This command will deleted all the compiled files
make re
```

Remove all compiled files (*.o) :
```shell
make clean
```

<p>Remove all compiled files (*.o), all compiled libs (*.a), all unit tests and program executable  :</p>

```shell
make fclean
```

Make a unit_tests file :
```shell
make unit_tests
```

Make and run a unit_tests file with the coverage :
```shell
make tests_run
```

### How to use it ?
Player 1 :
```Shell
./my_navy [map]
```
Player 2 :
```Shell
./my_navy [player_one_pid] [map]
```

### How to create a valid map ?
To make a valid map, you need a file containing 4 boats in this form : `[length]:[start_position]:[end_position]`.     
Each boat must be a different size. Boats can't be diagonal, cross each other or be on the same coordinates.

Example :
```Shell
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
```

### Final result on my.epitech.eu
|                      Test name                       | Status |
|:----------------------------------------------------:|:------:|
|                   Is not a cheater                   |   ✅    |
|                  Player connection                   |   ✅    |
|              Player waiting connection               |   ✅    |
|               2 boats has same length                |   ✅    |
|                   Bad boat length                    |   ✅    |
|                    Bad file path                     |   ✅    |
|                 Miss argument split                  |   ✅    |
|                 Miss argument value                  |   ✅    |
|                    Miss one boat                     |   ✅    |
|                  Too few arguments                   |   ✅    |
|                 Wrong argument value                 |   ✅    |
|                   Player 2 attack                    |   ✅    |
|               Player 1 wait for attack               |   ✅    |
|                   Player 2 attack                    |   ❌    |
|               Player 2 wait for attack               |   ✅    |
|                Player 1 attack - eval                |   ✅    |
|           Player 1 wait for attack - eval            |   ❌    |
|                Player 2 attack - eval                |   ❌    |
|           Player 2 wait for attack - eval            |   ✅    |
|          Attack again after wrong position           |   ✅    |
|              Attack same position twice              |   ✅    |
|               Attack wrong position 1                |   ✅    |
|               Attack wrong position 2                |   ✅    |
|               Attack wrong position 3                |   ✅    |
|                       Game end                       |   ❌    |
|                 Player 1 attack hit                  |   ❌    |
|                Player 1 attack missed                |   ❌    |
|       Attack again after wrong position - eval       |   ✅    |
|          Attack same position twice - eval           |   ❌    |
|            Attack wrong position 1 - eval            |   ✅    |
|            Attack wrong position 2 - eval            |   ✅    |
|            Attack wrong position 3 - eval            |   ✅    |
|                   Game end - eval                    |   ✅    |
|              Player 1 attack hit - eval              |   ✅    |
|            Player 1 attack missed - eval             |   ✅    |

I obtained **83.7%** with **98% lines** and **89%** branches in the last test.