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
	str0 BYTE "TestText20", 0
	short1 SDWORD 2
	short2 SDWORD 0
	short3 SDWORD 1
	str4 BYTE "teststring", 0
	bool5 DWORD 1
	str6 BYTE "Арифметические операции:", 0
	short7 SDWORD 15
	short8 SDWORD 10
	short9 SDWORD 5
	str10 BYTE "Умножение:", 0
	short11 SDWORD 10
	short12 SDWORD 5
	str13 BYTE "Деление:", 0
	short14 SDWORD 15
	short15 SDWORD 10
	str16 BYTE "Деление с остатком:", 0
	short17 SDWORD 10
	short18 SDWORD 5
	str19 BYTE "Сумма:", 0
	short20 SDWORD 10
	short21 SDWORD 5
	str22 BYTE "Разница:", 0
	short23 SDWORD 5
	short24 SDWORD 5
	short25 SDWORD 5
	str26 BYTE "Приоритет (=30):", 0
	short27 SDWORD 5
	short28 SDWORD 5
	short29 SDWORD 5
	str30 BYTE "Приоритет (=2):", 0
	str31 BYTE "TestText1", 0
	short32 SDWORD 0
	short33 SDWORD 5
	short34 SDWORD 10
	str35 BYTE "Тестовая строчка", 0
	str36 BYTE "125", 0
	short37 SDWORD 0
	short38 SDWORD 10
	short39 SDWORD 1
.DATA
	res10 SDWORD 0
	parm231 DWORD ?
	phah57 DWORD 0
	it76 SDWORD 0
	st76 DWORD ?
	bt76 DWORD 0
	a76 SDWORD 0
	b76 SDWORD 0
	parm176 DWORD ?
	number76 SDWORD 0
	pravda76 DWORD 0
	stroka76 DWORD ?
	strokachislo76 DWORD ?
	copystr76 DWORD ?
	dlina76 SDWORD 0
	strchislo76 SDWORD 0
	i76 SDWORD 0

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

testfunc22 PROC parm12 : DWORD
	push offset str0
	pop parm231
	push parm12
	jmp local1
local1:
	pop eax
	ret
testfunc22 ENDP

testfunc43 PROC chetnoe3 : SDWORD
	push chetnoe3
	pop ebx
	pop eax
	cmp ebx,0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push edx
	push short1
	push short2
	pop phah57
	push phah57
	jmp local2
local2:
	pop eax
	ret
testfunc43 ENDP

main PROC
	push short3
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov it76, eax
	push offset str4
	pop st76
	push bool5
	pop bt76

push offset str6
call soutl
	push short7
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov b76, eax
	push short8
	push short9
	pop eax
	pop ebx
	mul ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a76, eax

push offset str10
call soutl

push a76
call noutl
	push short11
	push short12
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
	mov a76, eax

push offset str13
call soutl

push a76
call noutl
	push short14
	push short15
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
	mov a76, eax

push offset str16
call soutl

push a76
call noutl
	push short17
	push short18
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a76, eax

push offset str19
call soutl

push a76
call noutl
	push short20
	push short21
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a76, eax

push offset str22
call soutl

push a76
call noutl
	push short23
	push short24
	push short25
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
	mov a76, eax

push offset str26
call soutl

push a76
call noutl
	push short27
	push short28
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push short29
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
	mov a76, eax

push offset str30
call soutl

push a76
call noutl
	push offset str31
	pop parm176
	push short32
	push short33
	call testfunc11
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov number76, eax
	push short34
	call testfunc43
	push eax
	pop pravda76

push number76
call noutl

push parm176
call soutl
	mov eax, pravda76
	cmp eax, 0
	jz pravda760T
	jnz pravda760F

pravda760T:

push offset false
call soutl

jmp pravda760

pravda760F:

push offset true
call soutl

pravda760:
	push offset str35
	pop stroka76
	push offset str36
	pop strokachislo76
	push stroka76
	call _strlength
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov dlina76, eax
	push strokachislo76
	call _strtransint
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov strchislo76, eax

push copystr76
call soutl

push dlina76
call noutl

push strchislo76
call noutl
	push short37
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i76, eax
cycle1:
	mov eax, i76
	cmp eax, short38
	jge cycleEnd1

push i76
call noutl
	push i76
	push short39
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i76, eax
	jmp cycle1
cycleEnd1:
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