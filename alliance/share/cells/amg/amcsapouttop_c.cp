#cell1 amcsapouttop_c idps_symb compose *
# 21-Feb-95 12:25 21-Feb-95 12:25 mbkvti400 * .cp
# .
V 4 VTIcompose 1.1
A 2 5 75 65
B 2 5 75 65
F F
C vss 2 5 metal2 2 1 * * W vss
C vss 75 5 metal2 2 2 * * E vss
C vdd 2 65 metal2 2 3 * * W vdd
C vdd 75 65 metal2 2 4 * * E vdd
C cout 75 23 metal2 2 5 * * E cout
C b 2 11 metal 1 6 * * W b
C sum 52 5 metal 1 7 * * S sum
C mi 73 65 metal 1 8 * * N mi
C mi 73 5 metal 1 9 * * S mi
C cin 26 65 metal 1 10 * * N cin
C anext 22 5 metal 1 11 * * S anext
C cinnext 26 5 metal 1 12 * * S cinnext
C cinnext 2 23 metal2 2 13 * * W cinnext
C anext 22 65 metal 1 14 * * N anext
C sumnext 75 48 metal2 2 15 * * E sumnext
C sumnext 52 65 metal 1 16 * * N sumnext
I via1 4 48 0 "cvia" ly * *
I cpf1 4 62 0 "cpf" ly * *
I cpf2 11 51 0 "cpf" ly * *
I cdp1 11 55 0 "cdp" ly * *
I cdp2 16 46 0 "cdp" ly * *
I cdp3 14 65 0 "cdp" ly * *
I via2 9 65 0 "cvia" ly * *
I cdn1 18 30 0 "cdn" ly * *
I cdp4 10 42 0 "cdp" ly * *
I cpf3 18 35 0 "cpf" ly * *
I cdn2 18 24 0 "cdn" ly * *
I cpf4 13 35 0 "cpf" ly * *
I cdn3 10 28 0 "cdn" ly * *
I cdn4 4 28 0 "cdn" ly * *
I cpf5 4 20 0 "cpf" ly * *
I cpf6 13 7 0 "cpf" ly * *
I cdn5 8 11 0 "cdn" ly * *
I cdn6 10 17 0 "cdn" ly * *
I via3 18 5 0 "cvia" ly * *
I via4 26 23 0 "cvia" ly * *
I cdp5 30 42 0 "cdp" ly * *
I cpf7 26 37 0 "cpf" ly * *
I cdn7 35 29 0 "cdn" ly * *
I cpf8 30 12 0 "cpf" ly * *
I cdn8 41 29 0 "cdn" ly * *
I cdn9 49 30 0 "cdn" ly * *
I cpf9 41 20 0 "cpf" ly * *
I cpf10 34 37 0 "cpf" ly * *
I cdn10 35 17 0 "cdn" ly * *
I cdp6 30 55 0 "cdp" ly * *
I cpf11 49 37 0 "cpf" ly * *
I cdp7 30 65 0 "cdp" ly * *
I via5 36 65 0 "cvia" ly * *
I cdp8 36 51 0 "cdp" ly * *
I cdp9 42 43 0 "cdp" ly * *
I cdp10 51 42 0 "cdp" ly * *
I cdp11 56 48 0 "cdp" ly * *
I cdp12 56 62 0 "cdp" ly * *
I cdn11 54 23 0 "cdn" ly * *
I cdn12 64 11 0 "cdn" ly * *
I via6 62 5 0 "cvia" ly * *
I cdn13 67 5 0 "cdn" ly * *
I cdn14 57 5 0 "cdn" ly * *
I cdn15 58 17 0 "cdn" ly * *
I cpf12 60 35 0 "cpf" ly * *
I cdp13 63 53 0 "cdp" ly * *
I via7 63 65 0 "cvia" ly * *
I cdp14 69 44 0 "cdp" ly * *
I cdn16 64 17 0 "cdn" ly * *
I via8 50 48 0 "cvia" ly * *
I cdn17 68 29 0 "cdn" ly * *
I via9 69 23 0 "cvia" ly * *
I cdn18 64 23 0 "cdn" ly * *
I cdp15 48 56 0 "cdp" ly * *
I via10 35 5 0 "cvia" ly * *
I cbp1 39 5 0 "cbp" ly * *
I cbn1 68 65 0 "cbn" ly * *
I via11 22 48 0 "cvia" ly * *
I sumnext_out 50 48 0 "ref_con" ly * *
P 2 65 * metal2
P 75 65 * metal2
W -4 59 81 71
S 6 H metal2 P 1 P 2
P 4 48 * metal2
P 22 48 * metal2
W 2 46 24 50
S 2 H metal2 P 3 P 4
P 4 20 * metal
P 4 62 * metal
W 3 19 5 63 a
S 1 V metal P 5 P 6
P 4 62 * poly
P 7 62 * poly
W 3 61 8 63
S 1 H poly P 7 P 8
P 7 62 * ptrans
P 20 62 * ptrans
W 6 61 21 63
S 1 H ptrans P 9 P 10
P 7 58 * ptrans
P 20 58 * ptrans
W 6 57 21 59
S 1 H ptrans P 11 P 12
P 13 39 * ptrans
P 13 50 * ptrans
W 12 38 14 51
S 1 V ptrans P 13 P 14
P 7 32 * poly
P 7 58 * poly
W 6 31 8 59
S 1 V poly P 15 P 16
P 13 27 * poly
P 13 32 * poly
W 12 26 14 33
S 1 V poly P 17 P 18
P 10 41 * pdif
P 10 48 * pdif
W 7 38 13 51
S 3 V pdif P 19 P 20
P 16 41 * pdif
P 16 48 * pdif
W 14 39 18 50
S 2 V pdif P 21 P 22
P 9 65 * pdif
P 18 65 * pdif
W 6 62 21 68
S 3 H pdif P 23 P 24
P 13 50 * poly
P 13 51 * poly
W 12 49 14 52
S 1 V poly P 25 P 26
P 13 27 * ntrans
P 32 27 * ntrans
W 12 26 33 28
S 1 H ntrans P 27 P 28
P 15 30 * ndif
P 30 30 * ndif
W 12 27 33 33
S 3 H ndif P 29 P 30
P 24 24 * ndif
P 25 24 * ndif
W 22 22 27 26
S 2 H ndif P 31 P 32
P 18 30 * metal
P 18 42 * metal
W 17 29 19 43
S 1 V metal P 33 P 34
P 18 35 * poly
P 22 35 * poly
W 17 34 23 36
S 1 H poly P 35 P 36
P 25 39 * ptrans
P 25 52 * ptrans
W 24 38 26 53
S 1 V ptrans P 37 P 38
P 17 20 * ntrans
P 40 20 * ntrans
W 16 19 41 21
S 1 H ntrans P 39 P 40
P 2 23 * metal2
P 26 23 * metal2
W 0 21 28 25
S 2 H metal2 P 41 P 42
P 26 29 * metal
P 35 29 * metal
W 25 28 36 30
S 1 H metal P 43 P 44
P 16 46 * metal
P 16 65 * metal
W 15 45 17 66
S 1 V metal P 45 P 46
P 26 29 * metal
P 26 65 * metal
W 25 28 27 66
S 1 V metal P 47 P 48
P 7 24 * ntrans
P 7 32 * ntrans
W 6 23 8 33
S 1 V ntrans P 49 P 50
P 6 14 * ntrans
P 14 14 * ntrans
W 5 13 15 15
S 1 H ntrans P 51 P 52
P 10 26 * ndif
P 10 30 * ndif
W 7 23 13 33
S 3 V ndif P 53 P 54
P 10 17 * metal
P 10 28 * metal
W 9 16 11 29 s1_s
S 1 V metal P 55 P 56
P 2 11 * metal
P 8 11 * metal
W 1 10 9 12 b
S 1 H metal P 57 P 58
P 4 26 * ndif
P 4 30 * ndif
W 1 23 7 33
S 3 V ndif P 59 P 60
P 6 14 * poly
P 6 20 * poly
W 5 13 7 21
S 1 V poly P 61 P 62
P 13 20 * poly
P 14 20 * poly
W 12 19 15 21
S 1 H poly P 63 P 64
P 9 65 * metal
P 16 65 * metal
W 7 63 18 67
S 2 H metal P 65 P 66
P 7 24 * poly
P 13 24 * poly
W 6 23 14 25
S 1 H poly P 67 P 68
P 13 20 * poly
P 13 24 * poly
W 12 19 14 25
S 1 V poly P 69 P 70
P 4 20 * poly
P 6 20 * poly
W 3 19 7 21
S 1 H poly P 71 P 72
P 8 17 * ndif
P 12 17 * ndif
W 5 14 15 20
S 3 H ndif P 73 P 74
P 8 11 * ndif
P 12 11 * ndif
W 5 8 15 14
S 3 H ndif P 75 P 76
P 26 5 * metal
P 26 23 * metal
W 25 4 27 24
S 1 V metal P 77 P 78
P 17 11 * poly
P 17 17 * poly
W 16 10 18 18
S 1 V poly P 79 P 80
P 20 62 * ptrans
P 33 62 * ptrans
W 19 61 34 63
S 1 H ptrans P 81 P 82
P 20 58 * ptrans
P 33 58 * ptrans
W 19 57 34 59
S 1 H ptrans P 83 P 84
P 46 45 * ptrans
P 59 45 * ptrans
W 45 44 60 46
S 1 H ptrans P 85 P 86
P 46 52 * ptrans
P 59 52 * ptrans
W 45 51 60 53
S 1 H ptrans P 87 P 88
P 66 40 * ptrans
P 66 57 * ptrans
W 65 39 67 58
S 1 V ptrans P 89 P 90
P 19 39 * ptrans
P 19 52 * ptrans
W 18 38 20 53
S 1 V ptrans P 91 P 92
P 10 42 * metal
P 18 42 * metal
W 9 41 19 43
S 1 H metal P 93 P 94
P 22 33 * poly
P 41 33 * poly
W 21 32 42 34
S 1 H poly P 95 P 96
P 29 41 * pdif
P 29 50 * pdif
W 25 37 33 54
S 4 V pdif P 97 P 98
P 25 37 * poly
P 25 39 * poly
W 24 36 26 40
S 1 V poly P 99 P 100
P 25 37 * poly
P 26 37 * poly
W 24 36 27 38
S 1 H poly P 101 P 102
P 38 25 * ntrans
P 38 33 * ntrans
W 37 24 39 34
S 1 V ntrans P 103 P 104
P 15 23 * ndif
P 30 23 * ndif
W 12 20 33 26
S 3 H ndif P 105 P 106
P 18 5 * metal
P 18 24 * metal
W 17 4 19 25
S 1 V metal P 107 P 108
P 35 27 * ndif
P 35 31 * ndif
W 32 24 38 34
S 3 V ndif P 109 P 110
P 41 27 * ndif
P 41 31 * ndif
W 39 25 43 33
S 2 V ndif P 111 P 112
P 19 17 * ndif
P 38 17 * ndif
W 16 14 41 20
S 3 H ndif P 113 P 114
P 44 25 * ntrans
P 44 33 * ntrans
W 43 24 45 34
S 1 V ntrans P 115 P 116
P 35 23 * metal
P 35 29 * metal
W 34 22 36 30 cin
S 1 V metal P 117 P 118
P 30 23 * metal
P 35 23 * metal
W 29 22 36 24
S 1 H metal P 119 P 120
P 30 12 * metal
P 30 23 * metal
W 29 11 31 24
S 1 V metal P 121 P 122
P 41 20 * metal
P 41 33 * metal
W 40 19 42 34 s2_s
S 1 V metal P 123 P 124
P 14 17 * poly
P 14 20 * poly
W 13 16 15 21
S 1 V poly P 125 P 126
P 14 17 * poly
P 17 17 * poly
W 13 16 18 18
S 1 H poly P 127 P 128
P 48 27 * ndif
P 48 31 * ndif
W 45 24 51 34
S 3 V ndif P 129 P 130
P 41 33 * poly
P 41 37 * poly
W 40 32 42 38
S 1 V poly P 131 P 132
P 30 13 * poly
P 43 13 * poly
W 29 12 44 14
S 1 H poly P 133 P 134
P 43 13 * poly
P 43 16 * poly
W 42 12 44 17
S 1 V poly P 135 P 136
P 40 20 * poly
P 41 20 * poly
W 39 19 42 21
S 1 H poly P 137 P 138
P 30 33 * metal
P 30 42 * metal
W 29 32 31 43
S 1 V metal P 139 P 140
P 30 33 * metal
P 41 33 * metal
W 29 32 42 34
S 1 H metal P 141 P 142
P 39 40 * ptrans
P 39 53 * ptrans
W 38 39 40 54
S 1 V ptrans P 143 P 144
P 2 5 * metal2
P 75 5 * metal2
W -6 -3 83 13
S 8 H metal2 P 145 P 146
P 34 33 * metal
P 34 37 * metal
W 33 32 35 38
S 1 V metal P 147 P 148
P 35 13 * metal
P 35 17 * metal
W 34 12 36 18
S 1 V metal P 149 P 150
P 22 65 * pdif
P 31 65 * pdif
W 19 62 34 68
S 3 H pdif P 151 P 152
P 48 62 * pdif
P 56 62 * pdif
W 45 59 59 65
S 3 H pdif P 153 P 154
P 33 62 * poly
P 46 62 * poly
W 32 61 47 63
S 1 H poly P 155 P 156
P 33 58 * poly
P 43 58 * poly
W 32 57 44 59
S 1 H poly P 157 P 158
P 46 59 * poly
P 46 62 * poly
W 45 58 47 63
S 1 V poly P 159 P 160
P 22 55 * pdif
P 31 55 * pdif
W 19 52 34 58
S 3 H pdif P 161 P 162
P 30 47 * metal
P 30 55 * metal
W 29 46 31 56
S 1 V metal P 163 P 164
P 30 47 * metal
P 46 47 * metal
W 29 46 47 48
S 1 H metal P 165 P 166
P 44 24 * poly
P 45 24 * poly
W 43 23 46 25
S 1 H poly P 167 P 168
P 45 16 * poly
P 45 24 * poly
W 44 15 46 25
S 1 V poly P 169 P 170
P 43 16 * poly
P 45 16 * poly
W 42 15 46 17
S 1 H poly P 171 P 172
P 44 24 * poly
P 44 25 * poly
W 43 23 45 26
S 1 V poly P 173 P 174
P 41 37 * poly
P 49 37 * poly
W 40 36 50 38
S 1 H poly P 175 P 176
P 48 42 * pdif
P 57 42 * pdif
W 45 39 60 45
S 3 H pdif P 177 P 178
P 30 65 * metal
P 36 65 * metal
W 29 64 37 66
S 1 H metal P 179 P 180
P 42 42 * pdif
P 42 51 * pdif
W 39 39 45 54
S 3 V pdif P 181 P 182
P 36 42 * pdif
P 36 51 * pdif
W 33 39 39 54
S 3 V pdif P 183 P 184
P 36 51 * metal
P 36 65 * metal
W 35 50 37 66
S 1 V metal P 185 P 186
P 43 53 * poly
P 45 53 * poly
W 42 52 46 54
S 1 H poly P 187 P 188
P 43 53 * poly
P 43 58 * poly
W 42 52 44 59
S 1 V poly P 189 P 190
P 49 30 * metal
P 49 37 * metal
W 48 29 50 38
S 1 V metal P 191 P 192
P 48 48 * pdif
P 57 48 * pdif
W 46 46 59 50
S 2 H pdif P 193 P 194
P 53 8 * ntrans
P 61 8 * ntrans
W 52 7 62 9
S 1 H ntrans P 195 P 196
P 52 14 * ntrans
P 60 14 * ntrans
W 51 13 61 15
S 1 H ntrans P 197 P 198
P 52 20 * ntrans
P 60 20 * ntrans
W 51 19 61 21
S 1 H ntrans P 199 P 200
P 61 8 * ntrans
P 69 8 * ntrans
W 60 7 70 9
S 1 H ntrans P 201 P 202
P 62 14 * ntrans
P 70 14 * ntrans
W 61 13 71 15
S 1 H ntrans P 203 P 204
P 60 26 * ntrans
P 70 26 * ntrans
W 59 25 71 27
S 1 H ntrans P 205 P 206
P 55 5 * ndif
P 59 5 * ndif
W 52 2 62 8
S 3 H ndif P 207 P 208
P 63 5 * ndif
P 67 5 * ndif
W 60 2 70 8
S 3 H ndif P 209 P 210
P 54 17 * ndif
P 58 17 * ndif
W 52 15 60 19
S 2 H ndif P 211 P 212
P 46 8 * poly
P 53 8 * poly
W 45 7 54 9
S 1 H poly P 213 P 214
P 54 23 * ndif
P 58 23 * ndif
W 51 20 61 26
S 3 H ndif P 215 P 216
P 65 11 * ndif
P 68 11 * ndif
W 63 9 70 13
S 2 H ndif P 217 P 218
P 54 11 * metal
P 64 11 * metal
W 53 10 65 12
S 1 H metal P 219 P 220
P 54 11 * metal
P 54 23 * metal
W 53 10 55 24
S 1 V metal P 221 P 222
P 57 5 * metal
P 68 5 * metal
W 56 4 69 6
S 1 H metal P 223 P 224
P 59 60 * poly
P 73 60 * poly
W 58 59 74 61
S 1 H poly P 225 P 226
P 73 18 * poly
P 73 60 * poly
W 72 17 74 61
S 1 V poly P 227 P 228
P 54 11 * ndif
P 58 11 * ndif
W 52 9 60 13
S 2 H ndif P 229 P 230
P 45 13 * metal
P 45 37 * metal
W 44 12 46 38
S 1 V metal P 231 P 232
P 35 13 * metal
P 45 13 * metal
W 34 12 46 14
S 1 H metal P 233 P 234
P 56 35 * metal
P 60 35 * metal
W 55 34 61 36
S 1 H metal P 235 P 236
P 58 17 * metal
P 58 27 * metal
W 57 16 59 28
S 1 V metal P 237 P 238
P 66 35 * poly
P 66 40 * poly
W 65 34 67 41
S 1 V poly P 239 P 240
P 60 35 * poly
P 66 35 * poly
W 59 34 67 36
S 1 H poly P 241 P 242
P 69 42 * pdif
P 69 55 * pdif
W 66 39 72 58
S 3 V pdif P 243 P 244
P 63 42 * pdif
P 63 55 * pdif
W 60 39 66 58
S 3 V pdif P 245 P 246
P 63 53 * metal
P 63 65 * metal
W 62 52 64 66
S 1 V metal P 247 P 248
P 69 23 * metal
P 69 44 * metal
W 68 22 70 45 cout
S 1 V metal P 249 P 250
P 73 5 * metal
P 73 65 * metal
W 72 4 74 66
S 1 V metal P 251 P 252
P 59 39 * poly
P 59 45 * poly
W 58 38 60 46
S 1 V poly P 253 P 254
P 56 39 * poly
P 59 39 * poly
W 55 38 60 40
S 1 H poly P 255 P 256
P 56 33 * poly
P 56 39 * poly
W 55 32 57 40
S 1 V poly P 257 P 258
P 50 48 * metal2
P 75 48 * metal2
W 48 46 77 50
S 2 H metal2 P 259 P 260
P 46 42 * metal
P 60 42 * metal
W 45 41 61 43
S 1 H metal P 261 P 262
P 60 35 * metal
P 60 42 * metal
W 59 34 61 43
S 1 V metal P 263 P 264
P 2 52 * nwell
P 75 52 * nwell
W -24 26 101 78
S 26 H nwell P 265 P 266
P 14 11 * poly
P 26 11 * poly
W 13 10 27 12
S 1 H poly P 267 P 268
P 26 8 * poly
P 26 11 * poly
W 25 7 27 12
S 1 V poly P 269 P 270
P 26 8 * poly
P 46 8 * poly
W 25 7 47 9
S 1 H poly P 271 P 272
P 60 14 * poly
P 62 14 * poly
W 59 13 63 15
S 1 H poly P 273 P 274
P 62 29 * ndif
P 68 29 * ndif
W 59 26 71 32
S 3 H ndif P 275 P 276
P 60 26 * poly
P 60 36 * poly
W 59 25 61 37
S 1 V poly P 277 P 278
P 44 33 * poly
P 56 33 * poly
W 43 32 57 34
S 1 H poly P 279 P 280
P 45 20 * poly
P 52 20 * poly
W 44 19 53 21
S 1 H poly P 281 P 282
P 69 23 * metal2
P 75 23 * metal2
W 67 21 77 25
S 2 H metal2 P 283 P 284
P 62 23 * ndif
P 68 23 * ndif
W 59 20 71 26
S 3 H ndif P 285 P 286
P 64 17 * metal
P 64 23 * metal
W 63 16 65 24
S 1 V metal P 287 P 288
P 68 29 * metal
P 69 29 * metal
W 67 28 70 30
S 1 H metal P 289 P 290
P 42 37 * metal
P 42 43 * metal
W 41 36 43 44
S 1 V metal P 291 P 292
P 42 37 * metal
P 45 37 * metal
W 41 36 46 38
S 1 H metal P 293 P 294
P 46 42 * metal
P 46 47 * metal
W 45 41 47 48
S 1 V metal P 295 P 296
P 50 48 * metal
P 50 52 * metal
W 49 47 51 53
S 1 V metal P 297 P 298
P 4 7 * metal
P 4 11 * metal
W 3 6 5 12
S 1 V metal P 299 P 300
P 14 7 * poly
P 14 11 * poly
W 13 6 15 12
S 1 V poly P 301 P 302
P 56 27 * metal
P 56 35 * metal
W 55 26 57 36
S 1 V metal P 303 P 304
P 56 27 * metal
P 58 27 * metal
W 55 26 59 28
S 1 H metal P 305 P 306
P 11 51 * metal
P 11 55 * metal
W 9 49 13 57
S 2 V metal P 307 P 308
P 4 7 * metal
P 13 7 * metal
W 3 6 14 8
S 1 H metal P 309 P 310
P 13 7 * poly
P 14 7 * poly
W 12 6 15 8
S 1 H poly P 311 P 312
P 34 37 * poly
P 38 37 * poly
W 33 36 39 38
S 1 H poly P 313 P 314
P 38 37 * poly
P 38 40 * poly
W 37 36 39 41
S 1 V poly P 315 P 316
P 38 40 * poly
P 39 40 * poly
W 37 39 40 41
S 1 H poly P 317 P 318
P 13 32 * poly
P 13 39 * poly
W 12 31 14 40
S 1 V poly P 319 P 320
P 14 28 * metal
P 14 35 * metal
W 13 27 15 36
S 1 V metal P 321 P 322
P 10 28 * metal
P 14 28 * metal
W 9 27 15 29
S 1 H metal P 323 P 324
P 13 35 * metal
P 14 35 * metal
W 12 34 15 36
S 1 H metal P 325 P 326
P 70 14 * poly
P 70 18 * poly
W 69 13 71 19
S 1 V poly P 327 P 328
P 70 18 * poly
P 73 18 * poly
W 69 17 74 19
S 1 H poly P 329 P 330
P 64 17 * metal
P 67 17 * metal
W 63 16 68 18
S 1 H metal P 331 P 332
P 67 17 * metal
P 68 17 * metal
W 66 16 69 18
S 1 H metal P 333 P 334
P 46 60 * poly
P 46 60 * poly
W 45 59 47 61
S 1 H poly P 335 P 336
P 56 48 * metal
P 56 62 * metal
W 55 47 57 63
S 1 V metal P 337 P 338
P 52 52 * metal
P 52 65 * metal
W 51 51 53 66
S 1 V metal P 339 P 340
P 50 52 * metal
P 52 52 * metal
W 49 51 53 53
S 1 H metal P 341 P 342
P 36 56 * metal
P 48 56 * metal
W 35 55 49 57
S 1 H metal P 343 P 344
P 52 5 * metal
P 52 7 * metal
W 51 4 53 8
S 1 V metal P 345 P 346
P 49 7 * metal
P 52 7 * metal
W 48 6 53 8
S 1 H metal P 347 P 348
P 45 52 * poly
P 45 53 * poly
W 44 51 46 54
S 1 V poly P 349 P 350
P 45 52 * poly
P 46 52 * poly
W 44 51 47 53
S 1 H poly P 351 P 352
P 48 49 * pdif
P 57 49 * pdif
W 46 47 59 51
S 2 H pdif P 353 P 354
P 59 59 * poly
P 59 60 * poly
W 58 58 60 61
S 1 V poly P 355 P 356
P 68 16 * metal
P 68 17 * metal
W 67 15 69 18
S 1 V metal P 357 P 358
P 68 5 * metal
P 68 16 * metal
W 67 4 69 17
S 1 V metal P 359 P 360
P 45 13 * metal
P 49 13 * metal
W 44 12 50 14 sum
S 1 H metal P 361 P 362
P 49 7 * metal
P 49 13 * metal
W 48 6 50 14
S 1 V metal P 363 P 364
P 63 65 * metal
P 68 65 * metal
W 61 63 70 67
S 2 H metal P 365 P 366
P 7 66 * nwell
P 38 66 * nwell
W 3 62 42 70
S 4 H nwell P 367 P 368
P 35 5 * metal
P 39 5 * metal
W 33 3 41 7
S 2 H metal P 369 P 370
P 61 66 * nwell
P 75 66 * nwell
W 57 62 79 70
S 4 H nwell P 371 P 372
P 46 59 * ptrans
P 59 59 * ptrans
W 45 58 60 60
S 1 H ptrans P 373 P 374
P 48 56 * pdif
P 57 56 * pdif
W 45 53 60 59
S 3 H pdif P 375 P 376
P 9 55 * pdif
P 18 55 * pdif
W 7 53 20 57
S 2 H pdif P 377 P 378
P 64 17 * ndif
P 68 17 * ndif
W 62 15 70 19
S 2 H ndif P 379 P 380
P 11 51 * poly
P 13 51 * poly
W 10 50 14 52
S 1 H poly P 381 P 382
P 22 5 * metal
P 22 65 * metal
W 21 4 23 66 a
S 1 V metal P 383 P 384
P 19 35 * poly
P 19 39 * poly
W 18 34 20 40
S 1 V poly P 385 P 386
P 22 33 * poly
P 22 35 * poly
W 21 32 23 36
S 1 V poly P 387 P 388
P 22 41 * pdif
P 22 50 * pdif
W 20 39 24 52
S 2 V pdif P 389 P 390
P 48 55 * pdif
P 57 55 * pdif
W 46 53 59 57
S 2 H pdif P 391 P 392
P 47 31 * ndif
P 47 27 * ndif
W 45 25 49 33
S 2 V ndif P 393 P 394
P 15 24 * ndif
P 30 24 * ndif
W 13 22 32 26
S 2 H ndif P 395 P 396
E