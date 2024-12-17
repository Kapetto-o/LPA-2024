.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib

ExitProcess PROTO:DWORD 
SYSPAUSE PROTO 
soutl PROTO : BYTE 
noutl PROTO : SDWORD 
_strduplicate PROTO  : BYTE, : BYTE 
_strlength PROTO  : BYTE 
_strtransint PROTO  : BYTE 

.STACK 4096

.CONST
	null_division BYTE 'ERROR: DIVISION BY ZERO', 0
	OVER_FLOW BYTE 'ERROR: OVERFLOW', 0
	true BYTE 'true', 0
	false BYTE 'false', 0
	str0 BYTE "TestText20", 0
	char1 BYTE 'М', 0
	short2 SDWORD 0
	short3 SDWORD 10
	short4 SDWORD 1
	short5 SDWORD 2
	short6 SDWORD 0
	short7 SDWORD 1
	char8 BYTE 'М', 0
	str9 BYTE "teststring", 0
	bool10 DWORD 1
	str11 BYTE "Арифметические операции:", 0
	short12 SDWORD 15
	short13 SDWORD 10
	short14 SDWORD 5
	str15 BYTE "Умножение:", 0
	short16 SDWORD 10
	short17 SDWORD 5
	str18 BYTE "Деление:", 0
	short19 SDWORD 15
	short20 SDWORD 10
	str21 BYTE "Деление с остатком:", 0
	short22 SDWORD 10
	short23 SDWORD 5
	str24 BYTE "Сумма:", 0
	short25 SDWORD 10
	short26 SDWORD 5
	str27 BYTE "Разница:", 0
	short28 SDWORD 5
	short29 SDWORD 5
	short30 SDWORD 5
	str31 BYTE "Приоритет (=30):", 0
	short32 SDWORD 5
	short33 SDWORD 5
	short34 SDWORD 5
	str35 BYTE "Приоритет (=2):", 0
	str36 BYTE "TestText1", 0
	char37 BYTE 'М', 0
	short38 SDWORD 0
	short39 SDWORD 5
	short40 SDWORD 10
	str41 BYTE "Тестовая строчка", 0
	str42 BYTE "125", 0
	short43 SDWORD 0
	short44 SDWORD 10
	short45 SDWORD 1
.DATA
	res10 SDWORD 0
	parm231 DWORD ?
	i57 SDWORD 0
	phah97 DWORD 0
	it116 SDWORD 0
	ct116 BYTE 0
	st116 DWORD ?
	bt116 DWORD 0
	a116 SDWORD 0
	b116 SDWORD 0
	parm1116 DWORD ?
	alpha116 BYTE 0
	number116 SDWORD 0
	pravda116 DWORD 0
	stroka116 DWORD ?
	strokachislo116 DWORD ?
	copystr116 DWORD ?
	dlina116 SDWORD 0
	strchislo116 SDWORD 0
	i116 SDWORD 0

.CODE

testfunc11 PROC b1 : SDWORD, a1 : SDWORD
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

testfunc33 PROC simbol3 : BYTE
	push -858993460
	pop simbol3

	push short2
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i57, eax
startCycle1:
	mov eax, i57
	cmp eax, 10
	jge endCycle1
cycleBody1:

	mov al, simbol3
	push eax
	call soutl
	push i57
	push short4
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i57, eax
	push simbol3
	jmp local2
local2:
	pop eax
	ret
testfunc33 ENDP

testfunc44 PROC chetnoe4 : SDWORD
	push chetnoe4
	pop ebx
	pop eax
	cmp ebx,0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push edx
	push short5
	push short6
	pop phah97

	push phah97
	jmp local3
local3:
	pop eax
	ret
testfunc44 ENDP

main PROC
	push short7
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov it116, eax
	push -858993460
	pop ct116

	push offset str9
	pop st116

	push bool10
	pop bt116


push offset str11
call soutl
	push short12
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov b116, eax
	push short13
	push short14
	pop eax
	pop ebx
	mul ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a116, eax

push offset str15
call soutl

push a116
call noutl
	push short16
	push short17
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
	mov a116, eax

push offset str18
call soutl

push a116
call noutl
	push short19
	push short20
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
	mov a116, eax

push offset str21
call soutl

push a116
call noutl
	push short22
	push short23
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a116, eax

push offset str24
call soutl

push a116
call noutl
	push short25
	push short26
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov a116, eax

push offset str27
call soutl

push a116
call noutl
	push short28
	push short29
	push short30
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
	mov a116, eax

push offset str31
call soutl

push a116
call noutl
	push short32
	push short33
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push short34
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
	mov a116, eax

push offset str35
call soutl

push a116
call noutl
	push offset str36
	pop parm1116

	push -858993460
	pop alpha116

	push short38
	push short39
	call testfunc11
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov number116, eax
	push short40
	call testfunc44
	push eax
	pop pravda116


push number116
call noutl

push parm1116
call soutl

	mov al, alpha116
	push eax
	call soutl
	mov eax, pravda116
	cmp eax, 0
	jz boolFalse0

push offset true
call soutl
	jmp boolEnd0
boolFalse0:

push offset false
call soutl
boolEnd0:
	push offset str41
	pop stroka116

	push offset str42
	pop strokachislo116

	push stroka116
	call _strlength
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov dlina116, eax
	push strokachislo116
	call _strtransint
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov strchislo116, eax

push copystr116
call soutl

push dlina116
call noutl

push strchislo116
call noutl
	push short43
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i116, eax
startCycle2:
	mov eax, i116
	cmp eax, 10
	jge endCycle2
cycleBody2:

push i116
call noutl
	push i116
	push short45
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i116, eax
	call SYSPAUSE
	push 0
	call ExitProcess
SOMETHINGWRONG::
	push offset null_division
jmp THEEND
overflow::
	push offset OVER_FLOW
THEEND:
	call SYSPAUSE
	push -1
	call ExitProcess
main ENDP
end main	jmp startCycle2
endCycle2:
