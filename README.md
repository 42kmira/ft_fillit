# fillit

Hopefully this passes. It is an iterative bitwise version. I think I am done. Can't think of more things to do, if you
find improvements please message me or fill out an issue! Would love to become a better programmer :wink:

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
