# fillit

<br>
<img align="left" height="250" src="https://github.com/42kmira/ft_fillit/blob/master/resources/Untitled.png" />
<br>

This is my fillit project. It is one of the fastest ones I have seen among all the 42 campuses. The reason for this
is that since we know a max of 26 pieces are available we know a board size that will fit all such configurations of
pieces, even if they are placed inefficiently. Because of this we can allocate, on the stack mind you, the board size.
To step it up a notch we also don't use a char map, but rather a C bitfield. Through thoughtful encoding of each piece
I am able to place or remove each piece with a single with a single xor (^) expression. I am also able to and (&) a
piece with the board to check if the piece fits as well. To add to that when moving the piece to a different location, column,
all that needs to be done to align the piece is a bit shift (>>) operation. All of this can be done on the CPU register level
making it one of the faster bitwise implementations I have seen on that merit alone.

But if that was not enough, this implementation also uses a search pruning method that cuts down on the search space. Unnecessary
redundant placement of pieces are avoided by keeping track of the last placement of that **type** of piece. This pruning is algorithmically
safe and ensures that only redundant piece placements are avoided.

A flow chart of the project can be found in the [resources folder](https://github.com/MrColour/fillit/blob/master/resources/Fillit.pdf)
Below is partial flowchart.

<img height="400" src="https://github.com/MrColour/fillit/blob/master/resources/pdf_picture.png" />

Below are some timed test I did with the time command. Test can be found [here](https://github.com/MrColour/fillit/tree/master/resources)

```
ABB.CELLH
ABBCCELLH
AADDCEEFH
NDD.GGIFH
NNSGG.IFF
NKSSMJII.
PKSRMJJQQ
PKKRMMJQQ
PP.RROOOO
./fillit ../fillit_test/test_19_piece  105.34s user 0.15s system 98% cpu 1:46.56 total
```

```
ABB.C.DD
ABBCCDDG
AAE.CFFG
H.E.FFJG
HHEE.LJG
HIIIILJJ
.KK..LL.
KK......
./fillit ../fillit_test/test_13_piece  1.28s user 0.00s system 99% cpu 1.295 total
```

```
.DDEEKK
DDEEKKA
FFGGLLA
FFGGLLA
HHIIJJA
CHHIIJJ
CCCBBBB
./fillit ../fillit_test/test_12_piece  0.87s user 0.00s system 99% cpu 0.881 total
```

I have a graphical repo of [fillit](https://github.com/MrColour/graphic_fillit) if you wanna check it out. It displays the
board being solved in real time with some other neat things.

Many thanks to [akharrou](https://github.com/akharrou) whom I collaborated with to create the bitwise implementation found [here](https://github.com/akharrou/42-Project-Fillit). I used this as a base for this project and made changes as I felt right.
