# fillit

Hopefully this passes. It is an iterative bitwise version. There is only one more possible optimization that I can think of,
each piece can point to the last piece of the same type that has been placed. I partially have this optimization with the
g_place_prunning array that records the last piece of type[n]. But it can only record the last one and cannot backtrack
two prior (or more). Good luck, hope you make more improvements if you use this as a skeleton for you Fillit.

A flow chart of the project can be found in the [resources folder](https://github.com/MrColour/fillit/blob/master/resources/Fillit.pdf)
Below is partial flowchart.

<img height="400" src="https://github.com/MrColour/fillit/blob/master/resources/pdf_picture.png" />

Below is are two test I ran using this fillit:

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
./fillit ../fillit_test/test_19_piece  2933.77s user 9.67s system 98% cpu 49:37.72 total
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
./fillit ../fillit_test/test_13_piece  3.54s user 0.00s system 83% cpu 4.253 total
```

```
.DDEEKK
DDEEKKA
FFGGLLA
FFGGLLA
HHIIJJA
CHHIIJJ
CCCBBBB
./fillit ../fillit_test/test_12_piece  0.88s user 0.00s system 99% cpu 0.886 total
```

Test can be found [here](https://github.com/MrColour/fillit/tree/master/resources)
