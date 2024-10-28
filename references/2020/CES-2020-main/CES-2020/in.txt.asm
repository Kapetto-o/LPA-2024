;========================= шапка ==============================
.586
	.model flat, stdcall
	includelib libucrt.lib
	includelib kernel32.lib
	ExitProcess PROTO : DWORD

	EXTRN outUs : proc
	EXTRN outStr : proc
	EXTRN outBool : proc
	EXTRN outSymb : proc
	EXTRN TIME : proc
	EXTRN DATE : proc 

.stack 4096
;=================== сегмент констант =========================
.const
	L0 DWORD 'a'
	L1 BYTE 'CES-2020', 0
	L2 DWORD 6
	L3 DWORD 2
	L4 DWORD 9
	L5 DWORD 5
	L6 DWORD 11
	L7 DWORD 15
	L8 DWORD 3
;=================== сегмент данных ============================
.data
	mulans3 DWORD ?
	maxa7 DWORD ?
	maxans8 DWORD ?
	HEADc9 DWORD ?
	HEADs11 DWORD ?
	HEADq17 DWORD ?
	HEADw18 DWORD ?
	HEADe24 DWORD ?
;=================== сегмент кода ==============================

.code

mul0 PROC mulp11 : SDWORD, mulp22 : SDWORD
	push mulp11
	push mulp22
	pop ebx
	pop eax
	mul ebx
	cmp eax, 256
	jl OK0
	push 7
	push 4
	push eax
	call outUs
	push 0
	call ExitProcess
OK0:
	push eax
	pop mulans3
	mov eax, mulans3
	ret
mul0 ENDP

max4 PROC maxp15 : SDWORD, maxp26 : SDWORD
	push maxp15
	push maxp26
	pop ebx
	pop eax
	cmp eax, ebx
	jle M1
	push 1
	jmp M2
M1:
	push 0
M2:
	pop maxa7
;--------------------------условный блок------------------------------
	mov eax, maxa7
	cmp eax, 1
	jne W0
	push maxp15
	pop maxans8
	jmp W1
W0:
	push maxp26
	pop maxans8
W1:
;----------------------------------------------------------------------
	mov eax, maxans8
	ret
max4 ENDP

main PROC
	push L0
	pop HEADc9
	push HEADc9
		call outSymb
	push offset L1
	pop HEADs11
	push  HEADs11
		call outStr
;--------------------------условный блок------------------------------
	mov eax, L2
	cmp eax, L3
	je W2
	pop edx
	push offset L1
		call DATE
	push eax
	pop HEADs11
	jmp W3
W2:
	pop edx
	push L0
		call TIME
	push eax
	pop HEADs11
W3:
;----------------------------------------------------------------------
	push  HEADs11
		call outStr
	push L4
	push L5
	pop edx
	pop edx
	push L5
	push L4
		call max4
	push eax
	push L6
	push L7
	pop edx
	pop edx
	push L7
	push L6
		call max4
	push eax
	pop ebx
	pop eax
	add eax, ebx
	cmp eax, 256
	jl OK1
	push 15
	push 35
	push eax
	call outUs
	jmp ERROR
OK1:
	push eax
	pop HEADq17
	push L8
	push L3
	pop ebx
	pop eax
	cmp eax, ebx
	jge M9
	push 1
	jmp M10
M9:
	push 0
M10:
	push L3
	push HEADq17
	pop ebx
	pop eax
	add eax, ebx
	cmp eax, 256
	jl OK2
	push 17
	push 36
	push eax
	call outUs
	jmp ERROR
OK2:
	push eax
	pop ebx
	pop eax
	cdq
	cmp ebx, 0
	jne OK3
	push 12
	push 36
	push -2147483648
	call outUs
	jmp ERROR
OK3:
	div ebx
	push eax
	pop HEADw18
	push HEADq17
	push HEADw18
	pop edx
	pop edx
	push HEADw18
	push HEADq17
		call mul0
	push eax
	pop HEADe24
	push HEADe24
		call outUs
ERROR:
	push 0
	call ExitProcess
main ENDP
end main
;=============================================================
