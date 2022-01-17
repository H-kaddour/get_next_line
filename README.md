# Get_next_line
![image](img/gitnextline.jpg)

:wave:Hey y'all this project it's all about how to read lines in a `fd`.
The fuction that we allow to use is `read` `malloc` `free`, now if we use read it gonna read the whole file content but we want to read line by line so we have to make three fuctions one for reading the `fd` the second one counts the first line and allocate it and return it and the rest we allocate it in the third function, don't forget we use `BUFFER_SIZE` to specifie how much `read` function gonna read.

> The project PDF:
```
https://cdn.intra.42.fr/pdf/pdf/37926/en.subject.pdf
```
> Tester:
```
https://github.com/Tripouille/gnlTester.git
```
> Prototype:
```
char	*get_next_line(int fd);
```
> How to compile:
```
gcc -W -W -W -D BUFFER_SIZE=n files
```
### This are some articles to study the behaviors of get_next_line and static char:
1. Medium: [Check it out.](https://medium.com/my-journey-at-42-silicon-valley-as-a-non-cs-major/cadet-10-22-19-get-next-line-2a95678d4406)
2. Static char [Check it out.](https://www.geeksforgeeks.org/static-variables-in-c/)

# My final point:
I done the mandatory part and the bonus part, the bonus it's about reading content in every opened fd btw `The max opened fd in a pc is 1024` and take a look in `*str[fd] array of a pointer`.
![image](img/point.png)
**That's all thank u for reading, have a good one :rocket:**
