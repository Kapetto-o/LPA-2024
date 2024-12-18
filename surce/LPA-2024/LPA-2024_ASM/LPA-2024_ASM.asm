.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib

ExitProcess		PROTO :DWORD 
SYSPAUSE		PROTO 
soutl			PROTO :BYTE 
noutl			PROTO :SDWORD 
_strduplicate	PROTO :BYTE, :BYTE 
_strlength		PROTO :BYTE 
_strtransint	PROTO :BYTE 

.STACK 4096

.CONST
	null_division BYTE 'ERROR: DIVISION BY ZERO', 0
	OVER_FLOW BYTE 'ERROR: OVERFLOW', 0
	true BYTE 'true', 0
	false BYTE 'false', 0
	short0 SDWORD 5
	short1 SDWORD 1
	short2 SDWORD 1
	str3 BYTE "teststring", 0
	bool4 DWORD 1
	str5 BYTE "Арифметические операции:", 0
	short6 SDWORD 15
	short7 SDWORD 10
	short8 SDWORD 5
	str9 BYTE "Умножение:", 0
	short10 SDWORD 10
	short11 SDWORD 5
	str12 BYTE "Деление:", 0
	short13 SDWORD 15
	short14 SDWORD 10
	str15 BYTE "Деление с остатком:", 0
	short16 SDWORD 10
	short17 SDWORD 5
	str18 BYTE "Сумма:", 0
	short19 SDWORD 10
	short20 SDWORD 5
	str21 BYTE "Разница:", 0
	short22 SDWORD 5
	short23 SDWORD 5
	short24 SDWORD 5
	str25 BYTE "Приоритет (=30):", 0
	short26 SDWORD 5
	short27 SDWORD 5
	short28 SDWORD 5
	str29 BYTE "Приоритет (=2):", 0
	str30 BYTE "Пользовательские функции:", 0
	short31 SDWORD 0
	short32 SDWORD 5
	short33 SDWORD 10
	str34 BYTE "Библиотечные функции:", 0
	str35 BYTE "Тестовая строчка", 0
	str36 BYTE "125", 0
	str37 BYTE "test", 0
	str38 BYTE "testing", 0
	short39 SDWORD 0
	short40 SDWORD 10
	short41 SDWORD 1
	short42 SDWORD 0
	short43 SDWORD 10
	short44 SDWORD 10
	short45 SDWORD 0
	short46 SDWORD 1
	short47 SDWORD 1
.DATA
	res10 SDWORD 0
	prom31 SDWORD 0
	res31 DWORD 0
	it56 SDWORD 0
	st56 DWORD ?
	bt56 DWORD 0
	a56 SDWORD 0
	b56 SDWORD 0
	number56 SDWORD 0
	pravda56 DWORD 0
	stroka56 DWORD ?
	strokachislo56 DWORD ?
	copystr56 DWORD ?
	dlina56 SDWORD 0
	strchislo56 SDWORD 0
	i56 SDWORD 0
	ii56 SDWORD 0
	jj56 SDWORD 0

.CODE

testfunc11 PROC a1 : SDWORD, b1 : SDWORD
	push a1
	push b1
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov res10, eax
	push res10
	jmp local0
local0:
	pop eax
	ret
testfunc11 ENDP

testfunc22 PROC chetnoe2 : SDWORD
	push chetnoe2
	push short0
	pop ebx
	pop eax
	cmp ebx,0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push edx
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov prom31, eax
	push prom31
	push short1
	pop res31
	push res31
	jmp local1
local1:
	pop eax
	ret
testfunc22 ENDP

main PROC
	push short2
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov it56, eax
	push offset str3
	pop st56
	push bool4
	pop bt56

push offset str5
call soutl
	push short6
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov b56, eax
	push short7
	push short8
	pop eax
	pop ebx
	mul ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a56, eax

push offset str9
call soutl

push a56
call noutl
	push short10
	push short11
	pop ebx
	pop eax
	cmp ebx,0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a56, eax

push offset str12
call soutl

push a56
call noutl
	push short13
	push short14
	pop ebx
	pop eax
	cmp ebx,0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push edx
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a56, eax

push offset str15
call soutl

push a56
call noutl
	push short16
	push short17
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a56, eax

push offset str18
call soutl

push a56
call noutl
	push short19
	push short20
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a56, eax

push offset str21
call soutl

push a56
call noutl
	push short22
	push short23
	push short24
	pop eax
	pop ebx
	mul ebx
	push eax
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a56, eax

push offset str25
call soutl

push a56
call noutl
	push short26
	push short27
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push short28
	pop ebx
	pop eax
	cmp ebx,0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a56, eax

push offset str29
call soutl

push a56
call noutl

push offset str30
call soutl
	push short31
	push short32
	call testfunc11
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov number56, eax
	push short33
	call testfunc22
	push eax
	pop pravda56

push number56
call noutl
	mov eax, pravda56
	cmp eax, 0
	jz pravda560T
	jnz pravda560F

pravda560T:
	push offset false
call soutl
	jmp pravda560

pravda560F:
	push offset true
call soutl

pravda560:

push offset str34
call soutl
	push offset str35
	pop stroka56
	push offset str36
	pop strokachislo56
	push offset str37
	push offset str38
	call _strduplicate
	push eax
	pop copystr56
	push stroka56
	call _strlength
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov dlina56, eax
	push strokachislo56
	call _strtransint
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov strchislo56, eax

push offset copystr56
call soutl

push dlina56
call noutl

push strchislo56
call noutl
	push short39
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i56, eax
cycle1:
	mov eax, i56
	cmp eax, short40
	jge cycleEnd1

push i56
call noutl
	push i56
	push short41
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i56, eax
	jmp cycle1
cycleEnd1:
	push short42
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov ii56, eax
	push short43
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov jj56, eax
cycle2:
	mov eax, ii56
	cmp eax, short44
	jge cycleEnd2
cycle3:
	mov eax, jj56
	cmp eax, short45
	jle cycleEnd3

push jj56
call noutl
	push jj56
	push short46
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov jj56, eax
	jmp cycle3
cycleEnd3:

push ii56
call noutl
	push ii56
	push short47
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov ii56, eax
	jmp cycle2
cycleEnd2:
	call SYSPAUSE
	push 0
	call ExitProcess
SOMETHINGWRONG::
	push offset null_division
	call soutl
jmp THEEND
overflow::
	push offset OVER_FLOW
	call soutl
THEEND:
	call SYSPAUSE
	push -1
	call ExitProcess
main ENDP
end main