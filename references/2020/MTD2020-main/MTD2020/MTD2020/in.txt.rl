----Протокол rl----
Время создания протокола: 17.12.2020 04:30:21, четверг
Шаг: Правило             Входная лента                 Стек               
0   : S->tfi(Q)[Y]S       tfi(ti)[ti:l.i:i+i.ri.]m[     S$                  
0   : SAVESTATE:          1
0   :                     tfi(ti)[ti:l.i:i+i.ri.]m[     tfi(Q)[Y]S$         
1   :                     fi(ti)[ti:l.i:i+i.ri.]m[t     fi(Q)[Y]S$          
2   :                     i(ti)[ti:l.i:i+i.ri.]m[ti     i(Q)[Y]S$           
3   :                     (ti)[ti:l.i:i+i.ri.]m[ti:     (Q)[Y]S$            
4   :                     ti)[ti:l.i:i+i.ri.]m[ti:l     Q)[Y]S$             
5   : Q->ti               ti)[ti:l.i:i+i.ri.]m[ti:l     Q)[Y]S$             
5   : SAVESTATE:          2
5   :                     ti)[ti:l.i:i+i.ri.]m[ti:l     ti)[Y]S$            
6   :                     i)[ti:l.i:i+i.ri.]m[ti:l.     i)[Y]S$             
7   :                     )[ti:l.i:i+i.ri.]m[ti:l.p     )[Y]S$              
8   :                     [ti:l.i:i+i.ri.]m[ti:l.p(     [Y]S$               
9   :                     ti:l.i:i+i.ri.]m[ti:l.p(i     Y]S$                
10  : Y->ti:E.Y           ti:l.i:i+i.ri.]m[ti:l.p(i     Y]S$                
10  : SAVESTATE:          3
10  :                     ti:l.i:i+i.ri.]m[ti:l.p(i     ti:E.Y]S$           
11  :                     i:l.i:i+i.ri.]m[ti:l.p(i)     i:E.Y]S$            
12  :                     :l.i:i+i.ri.]m[ti:l.p(i).     :E.Y]S$             
13  :                     l.i:i+i.ri.]m[ti:l.p(i).t     E.Y]S$              
14  : E->l                l.i:i+i.ri.]m[ti:l.p(i).t     E.Y]S$              
14  : SAVESTATE:          4
14  :                     l.i:i+i.ri.]m[ti:l.p(i).t     l.Y]S$              
15  :                     .i:i+i.ri.]m[ti:l.p(i).ti     .Y]S$               
16  :                     i:i+i.ri.]m[ti:l.p(i).ti:     Y]S$                
17  : Y->i:P.Y            i:i+i.ri.]m[ti:l.p(i).ti:     Y]S$                
17  : SAVESTATE:          5
17  :                     i:i+i.ri.]m[ti:l.p(i).ti:     i:P.Y]S$            
18  :                     :i+i.ri.]m[ti:l.p(i).ti:l     :P.Y]S$             
19  :                     i+i.ri.]m[ti:l.p(i).ti:l.     P.Y]S$              
20  : P->i                i+i.ri.]m[ti:l.p(i).ti:l.     P.Y]S$              
20  : SAVESTATE:          6
20  :                     i+i.ri.]m[ti:l.p(i).ti:l.     i.Y]S$              
21  :                     +i.ri.]m[ti:l.p(i).ti:l.t     .Y]S$               
22  : TS_NOK/NS_NORULECHAIN
22  : RESSTATE            
22  :                     i+i.ri.]m[ti:l.p(i).ti:l.     P.Y]S$              
23  : P->iP               i+i.ri.]m[ti:l.p(i).ti:l.     P.Y]S$              
23  : SAVESTATE:          6
23  :                     i+i.ri.]m[ti:l.p(i).ti:l.     iP.Y]S$             
24  :                     +i.ri.]m[ti:l.p(i).ti:l.t     P.Y]S$              
25  : TNS_NORULECHAIN/NS_NORULE
25  : RESSTATE            
25  :                     i+i.ri.]m[ti:l.p(i).ti:l.     P.Y]S$              
26  : P->iMP              i+i.ri.]m[ti:l.p(i).ti:l.     P.Y]S$              
26  : SAVESTATE:          6
26  :                     i+i.ri.]m[ti:l.p(i).ti:l.     iMP.Y]S$            
27  :                     +i.ri.]m[ti:l.p(i).ti:l.t     MP.Y]S$             
28  : M->+                +i.ri.]m[ti:l.p(i).ti:l.t     MP.Y]S$             
28  : SAVESTATE:          7
28  :                     +i.ri.]m[ti:l.p(i).ti:l.t     +P.Y]S$             
29  :                     i.ri.]m[ti:l.p(i).ti:l.ti     P.Y]S$              
30  : P->i                i.ri.]m[ti:l.p(i).ti:l.ti     P.Y]S$              
30  : SAVESTATE:          8
30  :                     i.ri.]m[ti:l.p(i).ti:l.ti     i.Y]S$              
31  :                     .ri.]m[ti:l.p(i).ti:l.ti:     .Y]S$               
32  :                     ri.]m[ti:l.p(i).ti:l.ti:s     Y]S$                
33  : Y->ri.              ri.]m[ti:l.p(i).ti:l.ti:s     Y]S$                
33  : SAVESTATE:          9
33  :                     ri.]m[ti:l.p(i).ti:l.ti:s     ri.]S$              
34  :                     i.]m[ti:l.p(i).ti:l.ti:s(     i.]S$               
35  :                     .]m[ti:l.p(i).ti:l.ti:s(i     .]S$                
36  :                     ]m[ti:l.p(i).ti:l.ti:s(i)     ]S$                 
37  :                     m[ti:l.p(i).ti:l.ti:s(i).     S$                  
38  : S->m[N]             m[ti:l.p(i).ti:l.ti:s(i).     S$                  
38  : SAVESTATE:          10
38  :                     m[ti:l.p(i).ti:l.ti:s(i).     m[N]$               
39  :                     [ti:l.p(i).ti:l.ti:s(i).p     [N]$                
40  :                     ti:l.p(i).ti:l.ti:s(i).p(     N]$                 
41  : N->ti:E.N           ti:l.p(i).ti:l.ti:s(i).p(     N]$                 
41  : SAVESTATE:          11
41  :                     ti:l.p(i).ti:l.ti:s(i).p(     ti:E.N]$            
42  :                     i:l.p(i).ti:l.ti:s(i).p(i     i:E.N]$             
43  :                     :l.p(i).ti:l.ti:s(i).p(i)     :E.N]$              
44  :                     l.p(i).ti:l.ti:s(i).p(i).     E.N]$               
45  : E->l                l.p(i).ti:l.ti:s(i).p(i).     E.N]$               
45  : SAVESTATE:          12
45  :                     l.p(i).ti:l.ti:s(i).p(i).     l.N]$               
46  :                     .p(i).ti:l.ti:s(i).p(i).t     .N]$                
47  :                     p(i).ti:l.ti:s(i).p(i).ti     N]$                 
48  : N->p(i).N           p(i).ti:l.ti:s(i).p(i).ti     N]$                 
48  : SAVESTATE:          13
48  :                     p(i).ti:l.ti:s(i).p(i).ti     p(i).N]$            
49  :                     (i).ti:l.ti:s(i).p(i).ti:     (i).N]$             
50  :                     i).ti:l.ti:s(i).p(i).ti:i     i).N]$              
51  :                     ).ti:l.ti:s(i).p(i).ti:i(     ).N]$               
52  :                     .ti:l.ti:s(i).p(i).ti:i(l     .N]$                
53  :                     ti:l.ti:s(i).p(i).ti:i(l)     N]$                 
54  : N->ti:E.N           ti:l.ti:s(i).p(i).ti:i(l)     N]$                 
54  : SAVESTATE:          14
54  :                     ti:l.ti:s(i).p(i).ti:i(l)     ti:E.N]$            
55  :                     i:l.ti:s(i).p(i).ti:i(l).     i:E.N]$             
56  :                     :l.ti:s(i).p(i).ti:i(l).p     :E.N]$              
57  :                     l.ti:s(i).p(i).ti:i(l).p(     E.N]$               
58  : E->l                l.ti:s(i).p(i).ti:i(l).p(     E.N]$               
58  : SAVESTATE:          15
58  :                     l.ti:s(i).p(i).ti:i(l).p(     l.N]$               
59  :                     .ti:s(i).p(i).ti:i(l).p(i     .N]$                
60  :                     ti:s(i).p(i).ti:i(l).p(i)     N]$                 
61  : N->ti:E.N           ti:s(i).p(i).ti:i(l).p(i)     N]$                 
61  : SAVESTATE:          16
61  :                     ti:s(i).p(i).ti:i(l).p(i)     ti:E.N]$            
62  :                     i:s(i).p(i).ti:i(l).p(i).     i:E.N]$             
63  :                     :s(i).p(i).ti:i(l).p(i).t     :E.N]$              
64  :                     s(i).p(i).ti:i(l).p(i).ti     E.N]$               
65  : E->s(i)             s(i).p(i).ti:i(l).p(i).ti     E.N]$               
65  : SAVESTATE:          17
65  :                     s(i).p(i).ti:i(l).p(i).ti     s(i).N]$            
66  :                     (i).p(i).ti:i(l).p(i).ti:     (i).N]$             
67  :                     i).p(i).ti:i(l).p(i).ti:~     i).N]$              
68  :                     ).p(i).ti:i(l).p(i).ti:~l     ).N]$               
69  :                     .p(i).ti:i(l).p(i).ti:~l.     .N]$                
70  :                     p(i).ti:i(l).p(i).ti:~l.p     N]$                 
71  : N->p(i).N           p(i).ti:i(l).p(i).ti:~l.p     N]$                 
71  : SAVESTATE:          18
71  :                     p(i).ti:i(l).p(i).ti:~l.p     p(i).N]$            
72  :                     (i).ti:i(l).p(i).ti:~l.p(     (i).N]$             
73  :                     i).ti:i(l).p(i).ti:~l.p(i     i).N]$              
74  :                     ).ti:i(l).p(i).ti:~l.p(i)     ).N]$               
75  :                     .ti:i(l).p(i).ti:~l.p(i).     .N]$                
76  :                     ti:i(l).p(i).ti:~l.p(i).t     N]$                 
77  : N->ti:E.N           ti:i(l).p(i).ti:~l.p(i).t     N]$                 
77  : SAVESTATE:          19
77  :                     ti:i(l).p(i).ti:~l.p(i).t     ti:E.N]$            
78  :                     i:i(l).p(i).ti:~l.p(i).ti     i:E.N]$             
79  :                     :i(l).p(i).ti:~l.p(i).ti:     :E.N]$              
80  :                     i(l).p(i).ti:~l.p(i).ti:l     E.N]$               
81  : E->i                i(l).p(i).ti:~l.p(i).ti:l     E.N]$               
81  : SAVESTATE:          20
81  :                     i(l).p(i).ti:~l.p(i).ti:l     i.N]$               
82  :                     (l).p(i).ti:~l.p(i).ti:l|     .N]$                
83  : TS_NOK/NS_NORULECHAIN
83  : RESSTATE            
83  :                     i(l).p(i).ti:~l.p(i).ti:l     E.N]$               
84  : E->i(O)             i(l).p(i).ti:~l.p(i).ti:l     E.N]$               
84  : SAVESTATE:          20
84  :                     i(l).p(i).ti:~l.p(i).ti:l     i(O).N]$            
85  :                     (l).p(i).ti:~l.p(i).ti:l|     (O).N]$             
86  :                     l).p(i).ti:~l.p(i).ti:l|l     O).N]$              
87  : TNS_NORULECHAIN/NS_NORULE
87  : RESSTATE            
87  :                     i(l).p(i).ti:~l.p(i).ti:l     E.N]$               
88  : TNS_NORULECHAIN/NS_NORULE
88  : RESSTATE            
88  :                     ti:i(l).p(i).ti:~l.p(i).t     N]$                 
89  : N->ti:E.            ti:i(l).p(i).ti:~l.p(i).t     N]$                 
89  : SAVESTATE:          19
89  :                     ti:i(l).p(i).ti:~l.p(i).t     ti:E.]$             
90  :                     i:i(l).p(i).ti:~l.p(i).ti     i:E.]$              
91  :                     :i(l).p(i).ti:~l.p(i).ti:     :E.]$               
92  :                     i(l).p(i).ti:~l.p(i).ti:l     E.]$                
93  : E->i                i(l).p(i).ti:~l.p(i).ti:l     E.]$                
93  : SAVESTATE:          20
93  :                     i(l).p(i).ti:~l.p(i).ti:l     i.]$                
94  :                     (l).p(i).ti:~l.p(i).ti:l|     .]$                 
95  : TS_NOK/NS_NORULECHAIN
95  : RESSTATE            
95  :                     i(l).p(i).ti:~l.p(i).ti:l     E.]$                
96  : E->i(O)             i(l).p(i).ti:~l.p(i).ti:l     E.]$                
96  : SAVESTATE:          20
96  :                     i(l).p(i).ti:~l.p(i).ti:l     i(O).]$             
97  :                     (l).p(i).ti:~l.p(i).ti:l|     (O).]$              
98  :                     l).p(i).ti:~l.p(i).ti:l|l     O).]$               
99  : TNS_NORULECHAIN/NS_NORULE
99  : RESSTATE            
99  :                     i(l).p(i).ti:~l.p(i).ti:l     E.]$                
100 : TNS_NORULECHAIN/NS_NORULE
100 : RESSTATE            
100 :                     ti:i(l).p(i).ti:~l.p(i).t     N]$                 
101 : N->tO.N             ti:i(l).p(i).ti:~l.p(i).t     N]$                 
101 : SAVESTATE:          19
101 :                     ti:i(l).p(i).ti:~l.p(i).t     tO.N]$              
102 :                     i:i(l).p(i).ti:~l.p(i).ti     O.N]$               
103 : O->i                i:i(l).p(i).ti:~l.p(i).ti     O.N]$               
103 : SAVESTATE:          20
103 :                     i:i(l).p(i).ti:~l.p(i).ti     i.N]$               
104 :                     :i(l).p(i).ti:~l.p(i).ti:     .N]$                
105 : TS_NOK/NS_NORULECHAIN
105 : RESSTATE            
105 :                     i:i(l).p(i).ti:~l.p(i).ti     O.N]$               
106 : O->i,O              i:i(l).p(i).ti:~l.p(i).ti     O.N]$               
106 : SAVESTATE:          20
106 :                     i:i(l).p(i).ti:~l.p(i).ti     i,O.N]$             
107 :                     :i(l).p(i).ti:~l.p(i).ti:     ,O.N]$              
108 : TS_NOK/NS_NORULECHAIN
108 : RESSTATE            
108 :                     i:i(l).p(i).ti:~l.p(i).ti     O.N]$               
109 : TNS_NORULECHAIN/NS_NORULE
109 : RESSTATE            
109 :                     ti:i(l).p(i).ti:~l.p(i).t     N]$                 
110 : N->tO.              ti:i(l).p(i).ti:~l.p(i).t     N]$                 
110 : SAVESTATE:          19
110 :                     ti:i(l).p(i).ti:~l.p(i).t     tO.]$               
111 :                     i:i(l).p(i).ti:~l.p(i).ti     O.]$                
112 : O->i                i:i(l).p(i).ti:~l.p(i).ti     O.]$                
112 : SAVESTATE:          20
112 :                     i:i(l).p(i).ti:~l.p(i).ti     i.]$                
113 :                     :i(l).p(i).ti:~l.p(i).ti:     .]$                 
114 : TS_NOK/NS_NORULECHAIN
114 : RESSTATE            
114 :                     i:i(l).p(i).ti:~l.p(i).ti     O.]$                
115 : O->i,O              i:i(l).p(i).ti:~l.p(i).ti     O.]$                
115 : SAVESTATE:          20
115 :                     i:i(l).p(i).ti:~l.p(i).ti     i,O.]$              
116 :                     :i(l).p(i).ti:~l.p(i).ti:     ,O.]$               
117 : TS_NOK/NS_NORULECHAIN
117 : RESSTATE            
117 :                     i:i(l).p(i).ti:~l.p(i).ti     O.]$                
118 : TNS_NORULECHAIN/NS_NORULE
118 : RESSTATE            
118 :                     ti:i(l).p(i).ti:~l.p(i).t     N]$                 
119 : N->ti:P.N           ti:i(l).p(i).ti:~l.p(i).t     N]$                 
119 : SAVESTATE:          19
119 :                     ti:i(l).p(i).ti:~l.p(i).t     ti:P.N]$            
120 :                     i:i(l).p(i).ti:~l.p(i).ti     i:P.N]$             
121 :                     :i(l).p(i).ti:~l.p(i).ti:     :P.N]$              
122 :                     i(l).p(i).ti:~l.p(i).ti:l     P.N]$               
123 : P->i                i(l).p(i).ti:~l.p(i).ti:l     P.N]$               
123 : SAVESTATE:          20
123 :                     i(l).p(i).ti:~l.p(i).ti:l     i.N]$               
124 :                     (l).p(i).ti:~l.p(i).ti:l|     .N]$                
125 : TS_NOK/NS_NORULECHAIN
125 : RESSTATE            
125 :                     i(l).p(i).ti:~l.p(i).ti:l     P.N]$               
126 : P->iP               i(l).p(i).ti:~l.p(i).ti:l     P.N]$               
126 : SAVESTATE:          20
126 :                     i(l).p(i).ti:~l.p(i).ti:l     iP.N]$              
127 :                     (l).p(i).ti:~l.p(i).ti:l|     P.N]$               
128 : P->(P)              (l).p(i).ti:~l.p(i).ti:l|     P.N]$               
128 : SAVESTATE:          21
128 :                     (l).p(i).ti:~l.p(i).ti:l|     (P).N]$             
129 :                     l).p(i).ti:~l.p(i).ti:l|l     P).N]$              
130 : P->l                l).p(i).ti:~l.p(i).ti:l|l     P).N]$              
130 : SAVESTATE:          22
130 :                     l).p(i).ti:~l.p(i).ti:l|l     l).N]$              
131 :                     ).p(i).ti:~l.p(i).ti:l|l.     ).N]$               
132 :                     .p(i).ti:~l.p(i).ti:l|l.t     .N]$                
133 :                     p(i).ti:~l.p(i).ti:l|l.ti     N]$                 
134 : N->p(i).N           p(i).ti:~l.p(i).ti:l|l.ti     N]$                 
134 : SAVESTATE:          23
134 :                     p(i).ti:~l.p(i).ti:l|l.ti     p(i).N]$            
135 :                     (i).ti:~l.p(i).ti:l|l.ti:     (i).N]$             
136 :                     i).ti:~l.p(i).ti:l|l.ti:l     i).N]$              
137 :                     ).ti:~l.p(i).ti:l|l.ti:l&     ).N]$               
138 :                     .ti:~l.p(i).ti:l|l.ti:l&l     .N]$                
139 :                     ti:~l.p(i).ti:l|l.ti:l&l.     N]$                 
140 : N->ti:E.N           ti:~l.p(i).ti:l|l.ti:l&l.     N]$                 
140 : SAVESTATE:          24
140 :                     ti:~l.p(i).ti:l|l.ti:l&l.     ti:E.N]$            
141 :                     i:~l.p(i).ti:l|l.ti:l&l.w     i:E.N]$             
142 :                     :~l.p(i).ti:l|l.ti:l&l.w(     :E.N]$              
143 :                     ~l.p(i).ti:l|l.ti:l&l.w(i     E.N]$               
144 : E->~i               ~l.p(i).ti:l|l.ti:l&l.w(i     E.N]$               
144 : SAVESTATE:          25
144 :                     ~l.p(i).ti:l|l.ti:l&l.w(i     ~i.N]$              
145 :                     l.p(i).ti:l|l.ti:l&l.w(i>     i.N]$               
146 : TS_NOK/NS_NORULECHAIN
146 : RESSTATE            
146 :                     ~l.p(i).ti:l|l.ti:l&l.w(i     E.N]$               
147 : E->~l               ~l.p(i).ti:l|l.ti:l&l.w(i     E.N]$               
147 : SAVESTATE:          25
147 :                     ~l.p(i).ti:l|l.ti:l&l.w(i     ~l.N]$              
148 :                     l.p(i).ti:l|l.ti:l&l.w(i>     l.N]$               
149 :                     .p(i).ti:l|l.ti:l&l.w(i>i     .N]$                
150 :                     p(i).ti:l|l.ti:l&l.w(i>i)     N]$                 
151 : N->p(i).N           p(i).ti:l|l.ti:l&l.w(i>i)     N]$                 
151 : SAVESTATE:          26
151 :                     p(i).ti:l|l.ti:l&l.w(i>i)     p(i).N]$            
152 :                     (i).ti:l|l.ti:l&l.w(i>i)[     (i).N]$             
153 :                     i).ti:l|l.ti:l&l.w(i>i)[p     i).N]$              
154 :                     ).ti:l|l.ti:l&l.w(i>i)[p(     ).N]$               
155 :                     .ti:l|l.ti:l&l.w(i>i)[p(i     .N]$                
156 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
157 : N->ti:E.N           ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
157 : SAVESTATE:          27
157 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     ti:E.N]$            
158 :                     i:l|l.ti:l&l.w(i>i)[p(i).     i:E.N]$             
159 :                     :l|l.ti:l&l.w(i>i)[p(i).]     :E.N]$              
160 :                     l|l.ti:l&l.w(i>i)[p(i).]e     E.N]$               
161 : E->l                l|l.ti:l&l.w(i>i)[p(i).]e     E.N]$               
161 : SAVESTATE:          28
161 :                     l|l.ti:l&l.w(i>i)[p(i).]e     l.N]$               
162 :                     |l.ti:l&l.w(i>i)[p(i).]e[     .N]$                
163 : TS_NOK/NS_NORULECHAIN
163 : RESSTATE            
163 :                     l|l.ti:l&l.w(i>i)[p(i).]e     E.N]$               
164 : TNS_NORULECHAIN/NS_NORULE
164 : RESSTATE            
164 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
165 : N->ti:E.            ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
165 : SAVESTATE:          27
165 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     ti:E.]$             
166 :                     i:l|l.ti:l&l.w(i>i)[p(i).     i:E.]$              
167 :                     :l|l.ti:l&l.w(i>i)[p(i).]     :E.]$               
168 :                     l|l.ti:l&l.w(i>i)[p(i).]e     E.]$                
169 : E->l                l|l.ti:l&l.w(i>i)[p(i).]e     E.]$                
169 : SAVESTATE:          28
169 :                     l|l.ti:l&l.w(i>i)[p(i).]e     l.]$                
170 :                     |l.ti:l&l.w(i>i)[p(i).]e[     .]$                 
171 : TS_NOK/NS_NORULECHAIN
171 : RESSTATE            
171 :                     l|l.ti:l&l.w(i>i)[p(i).]e     E.]$                
172 : TNS_NORULECHAIN/NS_NORULE
172 : RESSTATE            
172 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
173 : N->tO.N             ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
173 : SAVESTATE:          27
173 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     tO.N]$              
174 :                     i:l|l.ti:l&l.w(i>i)[p(i).     O.N]$               
175 : O->i                i:l|l.ti:l&l.w(i>i)[p(i).     O.N]$               
175 : SAVESTATE:          28
175 :                     i:l|l.ti:l&l.w(i>i)[p(i).     i.N]$               
176 :                     :l|l.ti:l&l.w(i>i)[p(i).]     .N]$                
177 : TS_NOK/NS_NORULECHAIN
177 : RESSTATE            
177 :                     i:l|l.ti:l&l.w(i>i)[p(i).     O.N]$               
178 : O->i,O              i:l|l.ti:l&l.w(i>i)[p(i).     O.N]$               
178 : SAVESTATE:          28
178 :                     i:l|l.ti:l&l.w(i>i)[p(i).     i,O.N]$             
179 :                     :l|l.ti:l&l.w(i>i)[p(i).]     ,O.N]$              
180 : TS_NOK/NS_NORULECHAIN
180 : RESSTATE            
180 :                     i:l|l.ti:l&l.w(i>i)[p(i).     O.N]$               
181 : TNS_NORULECHAIN/NS_NORULE
181 : RESSTATE            
181 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
182 : N->tO.              ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
182 : SAVESTATE:          27
182 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     tO.]$               
183 :                     i:l|l.ti:l&l.w(i>i)[p(i).     O.]$                
184 : O->i                i:l|l.ti:l&l.w(i>i)[p(i).     O.]$                
184 : SAVESTATE:          28
184 :                     i:l|l.ti:l&l.w(i>i)[p(i).     i.]$                
185 :                     :l|l.ti:l&l.w(i>i)[p(i).]     .]$                 
186 : TS_NOK/NS_NORULECHAIN
186 : RESSTATE            
186 :                     i:l|l.ti:l&l.w(i>i)[p(i).     O.]$                
187 : O->i,O              i:l|l.ti:l&l.w(i>i)[p(i).     O.]$                
187 : SAVESTATE:          28
187 :                     i:l|l.ti:l&l.w(i>i)[p(i).     i,O.]$              
188 :                     :l|l.ti:l&l.w(i>i)[p(i).]     ,O.]$               
189 : TS_NOK/NS_NORULECHAIN
189 : RESSTATE            
189 :                     i:l|l.ti:l&l.w(i>i)[p(i).     O.]$                
190 : TNS_NORULECHAIN/NS_NORULE
190 : RESSTATE            
190 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
191 : N->ti:P.N           ti:l|l.ti:l&l.w(i>i)[p(i)     N]$                 
191 : SAVESTATE:          27
191 :                     ti:l|l.ti:l&l.w(i>i)[p(i)     ti:P.N]$            
192 :                     i:l|l.ti:l&l.w(i>i)[p(i).     i:P.N]$             
193 :                     :l|l.ti:l&l.w(i>i)[p(i).]     :P.N]$              
194 :                     l|l.ti:l&l.w(i>i)[p(i).]e     P.N]$               
195 : P->l                l|l.ti:l&l.w(i>i)[p(i).]e     P.N]$               
195 : SAVESTATE:          28
195 :                     l|l.ti:l&l.w(i>i)[p(i).]e     l.N]$               
196 :                     |l.ti:l&l.w(i>i)[p(i).]e[     .N]$                
197 : TS_NOK/NS_NORULECHAIN
197 : RESSTATE            
197 :                     l|l.ti:l&l.w(i>i)[p(i).]e     P.N]$               
198 : P->lP               l|l.ti:l&l.w(i>i)[p(i).]e     P.N]$               
198 : SAVESTATE:          28
198 :                     l|l.ti:l&l.w(i>i)[p(i).]e     lP.N]$              
199 :                     |l.ti:l&l.w(i>i)[p(i).]e[     P.N]$               
200 : TNS_NORULECHAIN/NS_NORULE
200 : RESSTATE            
200 :                     l|l.ti:l&l.w(i>i)[p(i).]e     P.N]$               
201 : P->lMP              l|l.ti:l&l.w(i>i)[p(i).]e     P.N]$               
201 : SAVESTATE:          28
201 :                     l|l.ti:l&l.w(i>i)[p(i).]e     lMP.N]$             
202 :                     |l.ti:l&l.w(i>i)[p(i).]e[     MP.N]$              
203 : M->|                |l.ti:l&l.w(i>i)[p(i).]e[     MP.N]$              
203 : SAVESTATE:          29
203 :                     |l.ti:l&l.w(i>i)[p(i).]e[     |P.N]$              
204 :                     l.ti:l&l.w(i>i)[p(i).]e[p     P.N]$               
205 : P->l                l.ti:l&l.w(i>i)[p(i).]e[p     P.N]$               
205 : SAVESTATE:          30
205 :                     l.ti:l&l.w(i>i)[p(i).]e[p     l.N]$               
206 :                     .ti:l&l.w(i>i)[p(i).]e[p(     .N]$                
207 :                     ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
208 : N->ti:E.N           ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
208 : SAVESTATE:          31
208 :                     ti:l&l.w(i>i)[p(i).]e[p(i     ti:E.N]$            
209 :                     i:l&l.w(i>i)[p(i).]e[p(i)     i:E.N]$             
210 :                     :l&l.w(i>i)[p(i).]e[p(i).     :E.N]$              
211 :                     l&l.w(i>i)[p(i).]e[p(i).]     E.N]$               
212 : E->l                l&l.w(i>i)[p(i).]e[p(i).]     E.N]$               
212 : SAVESTATE:          32
212 :                     l&l.w(i>i)[p(i).]e[p(i).]     l.N]$               
213 :                     &l.w(i>i)[p(i).]e[p(i).]t     .N]$                
214 : TS_NOK/NS_NORULECHAIN
214 : RESSTATE            
214 :                     l&l.w(i>i)[p(i).]e[p(i).]     E.N]$               
215 : TNS_NORULECHAIN/NS_NORULE
215 : RESSTATE            
215 :                     ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
216 : N->ti:E.            ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
216 : SAVESTATE:          31
216 :                     ti:l&l.w(i>i)[p(i).]e[p(i     ti:E.]$             
217 :                     i:l&l.w(i>i)[p(i).]e[p(i)     i:E.]$              
218 :                     :l&l.w(i>i)[p(i).]e[p(i).     :E.]$               
219 :                     l&l.w(i>i)[p(i).]e[p(i).]     E.]$                
220 : E->l                l&l.w(i>i)[p(i).]e[p(i).]     E.]$                
220 : SAVESTATE:          32
220 :                     l&l.w(i>i)[p(i).]e[p(i).]     l.]$                
221 :                     &l.w(i>i)[p(i).]e[p(i).]t     .]$                 
222 : TS_NOK/NS_NORULECHAIN
222 : RESSTATE            
222 :                     l&l.w(i>i)[p(i).]e[p(i).]     E.]$                
223 : TNS_NORULECHAIN/NS_NORULE
223 : RESSTATE            
223 :                     ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
224 : N->tO.N             ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
224 : SAVESTATE:          31
224 :                     ti:l&l.w(i>i)[p(i).]e[p(i     tO.N]$              
225 :                     i:l&l.w(i>i)[p(i).]e[p(i)     O.N]$               
226 : O->i                i:l&l.w(i>i)[p(i).]e[p(i)     O.N]$               
226 : SAVESTATE:          32
226 :                     i:l&l.w(i>i)[p(i).]e[p(i)     i.N]$               
227 :                     :l&l.w(i>i)[p(i).]e[p(i).     .N]$                
228 : TS_NOK/NS_NORULECHAIN
228 : RESSTATE            
228 :                     i:l&l.w(i>i)[p(i).]e[p(i)     O.N]$               
229 : O->i,O              i:l&l.w(i>i)[p(i).]e[p(i)     O.N]$               
229 : SAVESTATE:          32
229 :                     i:l&l.w(i>i)[p(i).]e[p(i)     i,O.N]$             
230 :                     :l&l.w(i>i)[p(i).]e[p(i).     ,O.N]$              
231 : TS_NOK/NS_NORULECHAIN
231 : RESSTATE            
231 :                     i:l&l.w(i>i)[p(i).]e[p(i)     O.N]$               
232 : TNS_NORULECHAIN/NS_NORULE
232 : RESSTATE            
232 :                     ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
233 : N->tO.              ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
233 : SAVESTATE:          31
233 :                     ti:l&l.w(i>i)[p(i).]e[p(i     tO.]$               
234 :                     i:l&l.w(i>i)[p(i).]e[p(i)     O.]$                
235 : O->i                i:l&l.w(i>i)[p(i).]e[p(i)     O.]$                
235 : SAVESTATE:          32
235 :                     i:l&l.w(i>i)[p(i).]e[p(i)     i.]$                
236 :                     :l&l.w(i>i)[p(i).]e[p(i).     .]$                 
237 : TS_NOK/NS_NORULECHAIN
237 : RESSTATE            
237 :                     i:l&l.w(i>i)[p(i).]e[p(i)     O.]$                
238 : O->i,O              i:l&l.w(i>i)[p(i).]e[p(i)     O.]$                
238 : SAVESTATE:          32
238 :                     i:l&l.w(i>i)[p(i).]e[p(i)     i,O.]$              
239 :                     :l&l.w(i>i)[p(i).]e[p(i).     ,O.]$               
240 : TS_NOK/NS_NORULECHAIN
240 : RESSTATE            
240 :                     i:l&l.w(i>i)[p(i).]e[p(i)     O.]$                
241 : TNS_NORULECHAIN/NS_NORULE
241 : RESSTATE            
241 :                     ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
242 : N->ti:P.N           ti:l&l.w(i>i)[p(i).]e[p(i     N]$                 
242 : SAVESTATE:          31
242 :                     ti:l&l.w(i>i)[p(i).]e[p(i     ti:P.N]$            
243 :                     i:l&l.w(i>i)[p(i).]e[p(i)     i:P.N]$             
244 :                     :l&l.w(i>i)[p(i).]e[p(i).     :P.N]$              
245 :                     l&l.w(i>i)[p(i).]e[p(i).]     P.N]$               
246 : P->l                l&l.w(i>i)[p(i).]e[p(i).]     P.N]$               
246 : SAVESTATE:          32
246 :                     l&l.w(i>i)[p(i).]e[p(i).]     l.N]$               
247 :                     &l.w(i>i)[p(i).]e[p(i).]t     .N]$                
248 : TS_NOK/NS_NORULECHAIN
248 : RESSTATE            
248 :                     l&l.w(i>i)[p(i).]e[p(i).]     P.N]$               
249 : P->lP               l&l.w(i>i)[p(i).]e[p(i).]     P.N]$               
249 : SAVESTATE:          32
249 :                     l&l.w(i>i)[p(i).]e[p(i).]     lP.N]$              
250 :                     &l.w(i>i)[p(i).]e[p(i).]t     P.N]$               
251 : TNS_NORULECHAIN/NS_NORULE
251 : RESSTATE            
251 :                     l&l.w(i>i)[p(i).]e[p(i).]     P.N]$               
252 : P->lMP              l&l.w(i>i)[p(i).]e[p(i).]     P.N]$               
252 : SAVESTATE:          32
252 :                     l&l.w(i>i)[p(i).]e[p(i).]     lMP.N]$             
253 :                     &l.w(i>i)[p(i).]e[p(i).]t     MP.N]$              
254 : M->&                &l.w(i>i)[p(i).]e[p(i).]t     MP.N]$              
254 : SAVESTATE:          33
254 :                     &l.w(i>i)[p(i).]e[p(i).]t     &P.N]$              
255 :                     l.w(i>i)[p(i).]e[p(i).]ti     P.N]$               
256 : P->l                l.w(i>i)[p(i).]e[p(i).]ti     P.N]$               
256 : SAVESTATE:          34
256 :                     l.w(i>i)[p(i).]e[p(i).]ti     l.N]$               
257 :                     .w(i>i)[p(i).]e[p(i).]ti:     .N]$                
258 :                     w(i>i)[p(i).]e[p(i).]ti:l     N]$                 
259 : N->w(K)[N]e[N]N     w(i>i)[p(i).]e[p(i).]ti:l     N]$                 
259 : SAVESTATE:          35
259 :                     w(i>i)[p(i).]e[p(i).]ti:l     w(K)[N]e[N]N]$      
260 :                     (i>i)[p(i).]e[p(i).]ti:l.     (K)[N]e[N]N]$       
261 :                     i>i)[p(i).]e[p(i).]ti:l.t     K)[N]e[N]N]$        
262 : K->i                i>i)[p(i).]e[p(i).]ti:l.t     K)[N]e[N]N]$        
262 : SAVESTATE:          36
262 :                     i>i)[p(i).]e[p(i).]ti:l.t     i)[N]e[N]N]$        
263 :                     >i)[p(i).]e[p(i).]ti:l.ti     )[N]e[N]N]$         
264 : TS_NOK/NS_NORULECHAIN
264 : RESSTATE            
264 :                     i>i)[p(i).]e[p(i).]ti:l.t     K)[N]e[N]N]$        
265 : K->iBi              i>i)[p(i).]e[p(i).]ti:l.t     K)[N]e[N]N]$        
265 : SAVESTATE:          36
265 :                     i>i)[p(i).]e[p(i).]ti:l.t     iBi)[N]e[N]N]$      
266 :                     >i)[p(i).]e[p(i).]ti:l.ti     Bi)[N]e[N]N]$       
267 : B->>                >i)[p(i).]e[p(i).]ti:l.ti     Bi)[N]e[N]N]$       
267 : SAVESTATE:          37
267 :                     >i)[p(i).]e[p(i).]ti:l.ti     >i)[N]e[N]N]$       
268 :                     i)[p(i).]e[p(i).]ti:l.ti:     i)[N]e[N]N]$        
269 :                     )[p(i).]e[p(i).]ti:l.ti:l     )[N]e[N]N]$         
270 :                     [p(i).]e[p(i).]ti:l.ti:l.     [N]e[N]N]$          
271 :                     p(i).]e[p(i).]ti:l.ti:l.t     N]e[N]N]$           
272 : N->p(i).N           p(i).]e[p(i).]ti:l.ti:l.t     N]e[N]N]$           
272 : SAVESTATE:          38
272 :                     p(i).]e[p(i).]ti:l.ti:l.t     p(i).N]e[N]N]$      
273 :                     (i).]e[p(i).]ti:l.ti:l.ti     (i).N]e[N]N]$       
274 :                     i).]e[p(i).]ti:l.ti:l.ti:     i).N]e[N]N]$        
275 :                     ).]e[p(i).]ti:l.ti:l.ti:s     ).N]e[N]N]$         
276 :                     .]e[p(i).]ti:l.ti:l.ti:s(     .N]e[N]N]$          
277 :                     ]e[p(i).]ti:l.ti:l.ti:s(i     N]e[N]N]$           
278 : TNS_NORULECHAIN/NS_NORULE
278 : RESSTATE            
278 :                     p(i).]e[p(i).]ti:l.ti:l.t     N]e[N]N]$           
279 : N->p(i).            p(i).]e[p(i).]ti:l.ti:l.t     N]e[N]N]$           
279 : SAVESTATE:          38
279 :                     p(i).]e[p(i).]ti:l.ti:l.t     p(i).]e[N]N]$       
280 :                     (i).]e[p(i).]ti:l.ti:l.ti     (i).]e[N]N]$        
281 :                     i).]e[p(i).]ti:l.ti:l.ti:     i).]e[N]N]$         
282 :                     ).]e[p(i).]ti:l.ti:l.ti:s     ).]e[N]N]$          
283 :                     .]e[p(i).]ti:l.ti:l.ti:s(     .]e[N]N]$           
284 :                     ]e[p(i).]ti:l.ti:l.ti:s(i     ]e[N]N]$            
285 :                     e[p(i).]ti:l.ti:l.ti:s(i,     e[N]N]$             
286 :                     [p(i).]ti:l.ti:l.ti:s(i,i     [N]N]$              
287 :                     p(i).]ti:l.ti:l.ti:s(i,i)     N]N]$               
288 : N->p(i).N           p(i).]ti:l.ti:l.ti:s(i,i)     N]N]$               
288 : SAVESTATE:          39
288 :                     p(i).]ti:l.ti:l.ti:s(i,i)     p(i).N]N]$          
289 :                     (i).]ti:l.ti:l.ti:s(i,i).     (i).N]N]$           
290 :                     i).]ti:l.ti:l.ti:s(i,i).p     i).N]N]$            
291 :                     ).]ti:l.ti:l.ti:s(i,i).p(     ).N]N]$             
292 :                     .]ti:l.ti:l.ti:s(i,i).p(i     .N]N]$              
293 :                     ]ti:l.ti:l.ti:s(i,i).p(i)     N]N]$               
294 : TNS_NORULECHAIN/NS_NORULE
294 : RESSTATE            
294 :                     p(i).]ti:l.ti:l.ti:s(i,i)     N]N]$               
295 : N->p(i).            p(i).]ti:l.ti:l.ti:s(i,i)     N]N]$               
295 : SAVESTATE:          39
295 :                     p(i).]ti:l.ti:l.ti:s(i,i)     p(i).]N]$           
296 :                     (i).]ti:l.ti:l.ti:s(i,i).     (i).]N]$            
297 :                     i).]ti:l.ti:l.ti:s(i,i).p     i).]N]$             
298 :                     ).]ti:l.ti:l.ti:s(i,i).p(     ).]N]$              
299 :                     .]ti:l.ti:l.ti:s(i,i).p(i     .]N]$               
300 :                     ]ti:l.ti:l.ti:s(i,i).p(i)     ]N]$                
301 :                     ti:l.ti:l.ti:s(i,i).p(i).     N]$                 
302 : N->ti:E.N           ti:l.ti:l.ti:s(i,i).p(i).     N]$                 
302 : SAVESTATE:          40
302 :                     ti:l.ti:l.ti:s(i,i).p(i).     ti:E.N]$            
303 :                     i:l.ti:l.ti:s(i,i).p(i).t     i:E.N]$             
304 :                     :l.ti:l.ti:s(i,i).p(i).ti     :E.N]$              
305 :                     l.ti:l.ti:s(i,i).p(i).ti:     E.N]$               
306 : E->l                l.ti:l.ti:s(i,i).p(i).ti:     E.N]$               
306 : SAVESTATE:          41
306 :                     l.ti:l.ti:s(i,i).p(i).ti:     l.N]$               
307 :                     .ti:l.ti:s(i,i).p(i).ti:(     .N]$                
308 :                     ti:l.ti:s(i,i).p(i).ti:((     N]$                 
309 : N->ti:E.N           ti:l.ti:s(i,i).p(i).ti:((     N]$                 
309 : SAVESTATE:          42
309 :                     ti:l.ti:s(i,i).p(i).ti:((     ti:E.N]$            
310 :                     i:l.ti:s(i,i).p(i).ti:((l     i:E.N]$             
311 :                     :l.ti:s(i,i).p(i).ti:((l+     :E.N]$              
312 :                     l.ti:s(i,i).p(i).ti:((l+l     E.N]$               
313 : E->l                l.ti:s(i,i).p(i).ti:((l+l     E.N]$               
313 : SAVESTATE:          43
313 :                     l.ti:s(i,i).p(i).ti:((l+l     l.N]$               
314 :                     .ti:s(i,i).p(i).ti:((l+l)     .N]$                
315 :                     ti:s(i,i).p(i).ti:((l+l)/     N]$                 
316 : N->ti:E.N           ti:s(i,i).p(i).ti:((l+l)/     N]$                 
316 : SAVESTATE:          44
316 :                     ti:s(i,i).p(i).ti:((l+l)/     ti:E.N]$            
317 :                     i:s(i,i).p(i).ti:((l+l)/l     i:E.N]$             
318 :                     :s(i,i).p(i).ti:((l+l)/l)     :E.N]$              
319 :                     s(i,i).p(i).ti:((l+l)/l).     E.N]$               
320 : E->s(i)             s(i,i).p(i).ti:((l+l)/l).     E.N]$               
320 : SAVESTATE:          45
320 :                     s(i,i).p(i).ti:((l+l)/l).     s(i).N]$            
321 :                     (i,i).p(i).ti:((l+l)/l).p     (i).N]$             
322 :                     i,i).p(i).ti:((l+l)/l).p(     i).N]$              
323 :                     ,i).p(i).ti:((l+l)/l).p(i     ).N]$               
324 : TS_NOK/NS_NORULECHAIN
324 : RESSTATE            
324 :                     s(i,i).p(i).ti:((l+l)/l).     E.N]$               
325 : E->s(i,i)           s(i,i).p(i).ti:((l+l)/l).     E.N]$               
325 : SAVESTATE:          45
325 :                     s(i,i).p(i).ti:((l+l)/l).     s(i,i).N]$          
326 :                     (i,i).p(i).ti:((l+l)/l).p     (i,i).N]$           
327 :                     i,i).p(i).ti:((l+l)/l).p(     i,i).N]$            
328 :                     ,i).p(i).ti:((l+l)/l).p(i     ,i).N]$             
329 :                     i).p(i).ti:((l+l)/l).p(i)     i).N]$              
330 :                     ).p(i).ti:((l+l)/l).p(i).     ).N]$               
331 :                     .p(i).ti:((l+l)/l).p(i).]     .N]$                
332 :                     p(i).ti:((l+l)/l).p(i).]      N]$                 
333 : N->p(i).N           p(i).ti:((l+l)/l).p(i).]      N]$                 
333 : SAVESTATE:          46
333 :                     p(i).ti:((l+l)/l).p(i).]      p(i).N]$            
334 :                     (i).ti:((l+l)/l).p(i).]       (i).N]$             
335 :                     i).ti:((l+l)/l).p(i).]        i).N]$              
336 :                     ).ti:((l+l)/l).p(i).]         ).N]$               
337 :                     .ti:((l+l)/l).p(i).]          .N]$                
338 :                     ti:((l+l)/l).p(i).]           N]$                 
339 : N->ti:E.N           ti:((l+l)/l).p(i).]           N]$                 
339 : SAVESTATE:          47
339 :                     ti:((l+l)/l).p(i).]           ti:E.N]$            
340 :                     i:((l+l)/l).p(i).]            i:E.N]$             
341 :                     :((l+l)/l).p(i).]             :E.N]$              
342 :                     ((l+l)/l).p(i).]              E.N]$               
343 : TNS_NORULECHAIN/NS_NORULE
343 : RESSTATE            
343 :                     ti:((l+l)/l).p(i).]           N]$                 
344 : N->ti:E.            ti:((l+l)/l).p(i).]           N]$                 
344 : SAVESTATE:          47
344 :                     ti:((l+l)/l).p(i).]           ti:E.]$             
345 :                     i:((l+l)/l).p(i).]            i:E.]$              
346 :                     :((l+l)/l).p(i).]             :E.]$               
347 :                     ((l+l)/l).p(i).]              E.]$                
348 : TNS_NORULECHAIN/NS_NORULE
348 : RESSTATE            
348 :                     ti:((l+l)/l).p(i).]           N]$                 
349 : N->tO.N             ti:((l+l)/l).p(i).]           N]$                 
349 : SAVESTATE:          47
349 :                     ti:((l+l)/l).p(i).]           tO.N]$              
350 :                     i:((l+l)/l).p(i).]            O.N]$               
351 : O->i                i:((l+l)/l).p(i).]            O.N]$               
351 : SAVESTATE:          48
351 :                     i:((l+l)/l).p(i).]            i.N]$               
352 :                     :((l+l)/l).p(i).]             .N]$                
353 : TS_NOK/NS_NORULECHAIN
353 : RESSTATE            
353 :                     i:((l+l)/l).p(i).]            O.N]$               
354 : O->i,O              i:((l+l)/l).p(i).]            O.N]$               
354 : SAVESTATE:          48
354 :                     i:((l+l)/l).p(i).]            i,O.N]$             
355 :                     :((l+l)/l).p(i).]             ,O.N]$              
356 : TS_NOK/NS_NORULECHAIN
356 : RESSTATE            
356 :                     i:((l+l)/l).p(i).]            O.N]$               
357 : TNS_NORULECHAIN/NS_NORULE
357 : RESSTATE            
357 :                     ti:((l+l)/l).p(i).]           N]$                 
358 : N->tO.              ti:((l+l)/l).p(i).]           N]$                 
358 : SAVESTATE:          47
358 :                     ti:((l+l)/l).p(i).]           tO.]$               
359 :                     i:((l+l)/l).p(i).]            O.]$                
360 : O->i                i:((l+l)/l).p(i).]            O.]$                
360 : SAVESTATE:          48
360 :                     i:((l+l)/l).p(i).]            i.]$                
361 :                     :((l+l)/l).p(i).]             .]$                 
362 : TS_NOK/NS_NORULECHAIN
362 : RESSTATE            
362 :                     i:((l+l)/l).p(i).]            O.]$                
363 : O->i,O              i:((l+l)/l).p(i).]            O.]$                
363 : SAVESTATE:          48
363 :                     i:((l+l)/l).p(i).]            i,O.]$              
364 :                     :((l+l)/l).p(i).]             ,O.]$               
365 : TS_NOK/NS_NORULECHAIN
365 : RESSTATE            
365 :                     i:((l+l)/l).p(i).]            O.]$                
366 : TNS_NORULECHAIN/NS_NORULE
366 : RESSTATE            
366 :                     ti:((l+l)/l).p(i).]           N]$                 
367 : N->ti:P.N           ti:((l+l)/l).p(i).]           N]$                 
367 : SAVESTATE:          47
367 :                     ti:((l+l)/l).p(i).]           ti:P.N]$            
368 :                     i:((l+l)/l).p(i).]            i:P.N]$             
369 :                     :((l+l)/l).p(i).]             :P.N]$              
370 :                     ((l+l)/l).p(i).]              P.N]$               
371 : P->(P)              ((l+l)/l).p(i).]              P.N]$               
371 : SAVESTATE:          48
371 :                     ((l+l)/l).p(i).]              (P).N]$             
372 :                     (l+l)/l).p(i).]               P).N]$              
373 : P->(P)              (l+l)/l).p(i).]               P).N]$              
373 : SAVESTATE:          49
373 :                     (l+l)/l).p(i).]               (P)).N]$            
374 :                     l+l)/l).p(i).]                P)).N]$             
375 : P->l                l+l)/l).p(i).]                P)).N]$             
375 : SAVESTATE:          50
375 :                     l+l)/l).p(i).]                l)).N]$             
376 :                     +l)/l).p(i).]                 )).N]$              
377 : TS_NOK/NS_NORULECHAIN
377 : RESSTATE            
377 :                     l+l)/l).p(i).]                P)).N]$             
378 : P->lP               l+l)/l).p(i).]                P)).N]$             
378 : SAVESTATE:          50
378 :                     l+l)/l).p(i).]                lP)).N]$            
379 :                     +l)/l).p(i).]                 P)).N]$             
380 : TNS_NORULECHAIN/NS_NORULE
380 : RESSTATE            
380 :                     l+l)/l).p(i).]                P)).N]$             
381 : P->lMP              l+l)/l).p(i).]                P)).N]$             
381 : SAVESTATE:          50
381 :                     l+l)/l).p(i).]                lMP)).N]$           
382 :                     +l)/l).p(i).]                 MP)).N]$            
383 : M->+                +l)/l).p(i).]                 MP)).N]$            
383 : SAVESTATE:          51
383 :                     +l)/l).p(i).]                 +P)).N]$            
384 :                     l)/l).p(i).]                  P)).N]$             
385 : P->l                l)/l).p(i).]                  P)).N]$             
385 : SAVESTATE:          52
385 :                     l)/l).p(i).]                  l)).N]$             
386 :                     )/l).p(i).]                   )).N]$              
387 :                     /l).p(i).]                    ).N]$               
388 : TS_NOK/NS_NORULECHAIN
388 : RESSTATE            
388 :                     l)/l).p(i).]                  P)).N]$             
389 : P->lP               l)/l).p(i).]                  P)).N]$             
389 : SAVESTATE:          52
389 :                     l)/l).p(i).]                  lP)).N]$            
390 :                     )/l).p(i).]                   P)).N]$             
391 : TNS_NORULECHAIN/NS_NORULE
391 : RESSTATE            
391 :                     l)/l).p(i).]                  P)).N]$             
392 : P->lMP              l)/l).p(i).]                  P)).N]$             
392 : SAVESTATE:          52
392 :                     l)/l).p(i).]                  lMP)).N]$           
393 :                     )/l).p(i).]                   MP)).N]$            
394 : TNS_NORULECHAIN/NS_NORULE
394 : RESSTATE            
394 :                     l)/l).p(i).]                  P)).N]$             
395 : TNS_NORULECHAIN/NS_NORULE
395 : RESSTATE            
395 :                     +l)/l).p(i).]                 MP)).N]$            
396 : TNS_NORULECHAIN/NS_NORULE
396 : RESSTATE            
396 :                     l+l)/l).p(i).]                P)).N]$             
397 : TNS_NORULECHAIN/NS_NORULE
397 : RESSTATE            
397 :                     (l+l)/l).p(i).]               P).N]$              
398 : P->(P)MP            (l+l)/l).p(i).]               P).N]$              
398 : SAVESTATE:          49
398 :                     (l+l)/l).p(i).]               (P)MP).N]$          
399 :                     l+l)/l).p(i).]                P)MP).N]$           
400 : P->l                l+l)/l).p(i).]                P)MP).N]$           
400 : SAVESTATE:          50
400 :                     l+l)/l).p(i).]                l)MP).N]$           
401 :                     +l)/l).p(i).]                 )MP).N]$            
402 : TS_NOK/NS_NORULECHAIN
402 : RESSTATE            
402 :                     l+l)/l).p(i).]                P)MP).N]$           
403 : P->lP               l+l)/l).p(i).]                P)MP).N]$           
403 : SAVESTATE:          50
403 :                     l+l)/l).p(i).]                lP)MP).N]$          
404 :                     +l)/l).p(i).]                 P)MP).N]$           
405 : TNS_NORULECHAIN/NS_NORULE
405 : RESSTATE            
405 :                     l+l)/l).p(i).]                P)MP).N]$           
406 : P->lMP              l+l)/l).p(i).]                P)MP).N]$           
406 : SAVESTATE:          50
406 :                     l+l)/l).p(i).]                lMP)MP).N]$         
407 :                     +l)/l).p(i).]                 MP)MP).N]$          
408 : M->+                +l)/l).p(i).]                 MP)MP).N]$          
408 : SAVESTATE:          51
408 :                     +l)/l).p(i).]                 +P)MP).N]$          
409 :                     l)/l).p(i).]                  P)MP).N]$           
410 : P->l                l)/l).p(i).]                  P)MP).N]$           
410 : SAVESTATE:          52
410 :                     l)/l).p(i).]                  l)MP).N]$           
411 :                     )/l).p(i).]                   )MP).N]$            
412 :                     /l).p(i).]                    MP).N]$             
413 : M->/                /l).p(i).]                    MP).N]$             
413 : SAVESTATE:          53
413 :                     /l).p(i).]                    /P).N]$             
414 :                     l).p(i).]                     P).N]$              
415 : P->l                l).p(i).]                     P).N]$              
415 : SAVESTATE:          54
415 :                     l).p(i).]                     l).N]$              
416 :                     ).p(i).]                      ).N]$               
417 :                     .p(i).]                       .N]$                
418 :                     p(i).]                        N]$                 
419 : N->p(i).N           p(i).]                        N]$                 
419 : SAVESTATE:          55
419 :                     p(i).]                        p(i).N]$            
420 :                     (i).]                         (i).N]$             
421 :                     i).]                          i).N]$              
422 :                     ).]                           ).N]$               
423 :                     .]                            .N]$                
424 :                     ]                             N]$                 
425 : TNS_NORULECHAIN/NS_NORULE
425 : RESSTATE            
425 :                     p(i).]                        N]$                 
426 : N->p(i).            p(i).]                        N]$                 
426 : SAVESTATE:          55
426 :                     p(i).]                        p(i).]$             
427 :                     (i).]                         (i).]$              
428 :                     i).]                          i).]$               
429 :                     ).]                           ).]$                
430 :                     .]                            .]$                 
431 :                     ]                             ]$                  
432 :                                                   $                   
433 : LENTA_END           
434 : -------> NS_LENTA_END
--------------------------------------------------------------
Всего строк 156, Синтаксический анализ выполнен без ошибок
0   : S->tfi(Q)[Y]S       
4   : Q->ti               
8   : Y->ti:E.Y           
11  : E->l                
13  : Y->i:P.Y            
15  : P->iMP              
16  : M->+                
17  : P->i                
19  : Y->ri.              
23  : S->m[N]             
25  : N->ti:E.N           
28  : E->l                
30  : N->p(i).N           
35  : N->ti:E.N           
38  : E->l                
40  : N->ti:E.N           
43  : E->s(i)             
48  : N->p(i).N           
53  : N->ti:P.N           
56  : P->iP               
57  : P->(P)              
58  : P->l                
61  : N->p(i).N           
66  : N->ti:E.N           
69  : E->~l               
72  : N->p(i).N           
77  : N->ti:P.N           
80  : P->lMP              
81  : M->|                
82  : P->l                
84  : N->ti:P.N           
87  : P->lMP              
88  : M->&                
89  : P->l                
91  : N->w(K)[N]e[N]N     
93  : K->iBi              
94  : B->>                
98  : N->p(i).            
106 : N->p(i).            
112 : N->ti:E.N           
115 : E->l                
117 : N->ti:E.N           
120 : E->l                
122 : N->ti:E.N           
125 : E->s(i,i)           
132 : N->p(i).N           
137 : N->ti:P.N           
140 : P->(P)              
141 : P->(P)MP            
142 : P->lMP              
143 : M->+                
144 : P->l                
146 : M->/                
147 : P->l                
150 : N->p(i).            
