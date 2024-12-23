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
	short1 SDWORD 0
	short2 SDWORD 1
	str3 BYTE "teststring", 0
	bool4 DWORD 1
	str5 BYTE "�������������� ��������:", 0
	short6 SDWORD 15
	short7 SDWORD 10
	short8 SDWORD 5
	str9 BYTE "���������:", 0
	short10 SDWORD 10
	short11 SDWORD 5
	str12 BYTE "�������:", 0
	short13 SDWORD 15
	short14 SDWORD 10
	str15 BYTE "������� � ��������:", 0
	short16 SDWORD 10
	short17 SDWORD 5
	str18 BYTE "�����:", 0
	short19 SDWORD 10
	short20 SDWORD 5
	str21 BYTE "�������:", 0
	short22 SDWORD 5
	short23 SDWORD 5
	short24 SDWORD 5
	str25 BYTE "��������� (=30):", 0
	short26 SDWORD 5
	short27 SDWORD 5
	short28 SDWORD 5
	str29 BYTE "��������� (=2):", 0
	str30 BYTE "TestText1", 0
	short31 SDWORD 0
	short32 SDWORD 5
	short33 SDWORD 1
	short34 SDWORD 10
	str35 BYTE "�������� �������", 0
	str36 BYTE "125", 0
	short37 SDWORD 0
	short38 SDWORD 10
	short39 SDWORD 1
.DATA
	res10 SDWORD 0
	phah31 DWORD 0
	it50 SDWORD 0
	st50 DWORD ?
	bt50 DWORD 0
	a50 SDWORD 0
	b50 SDWORD 0
	parm150 DWORD ?
	number50 SDWORD 0
	pravda50 DWORD 0
	stroka50 DWORD ?
	strokachislo50 DWORD ?
	copystr50 DWORD ?
	dlina50 SDWORD 0
	strchislo50 SDWORD 0
	i50 SDWORD 0

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
	pop ebx
	pop eax
	cmp ebx,0
	je SOMETHINGWRONG
	cdq
	idiv ebx
	push edx
	push short0
	push short1
	pop phah31
	push phah31
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
	mov it50, eax
	push offset str3
	pop st50
	push bool4
	pop bt50

push offset str5
call soutl
	push short6
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov b50, eax
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
	mov a50, eax

push offset str9
call soutl

push a50
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
	mov a50, eax

push offset str12
call soutl

push a50
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
	mov a50, eax

push offset str15
call soutl

push a50
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
	mov a50, eax

push offset str18
call soutl

push a50
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
	mov a50, eax

push offset str21
call soutl

push a50
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
	mov a50, eax

push offset str25
call soutl

push a50
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
	mov a50, eax

push offset str29
call soutl

push a50
call noutl
	push offset str30
	pop parm150
	push short31
	push short32
	call testfunc11
	push eax
	push short33
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov number50, eax
	push short34
	call testfunc22
	push eax
	pop pravda50

push number50
call noutl

push offset parm150
call soutl
	mov eax, pravda50
	cmp eax, 0
	jz pravda500T
	jnz pravda500F

pravda500T:
	push offset false
call soutl
	jmp pravda500

pravda500F:
	push offset true
call soutl

pravda500:
	push offset str35
	pop stroka50
	push offset str36
	pop strokachislo50
	push stroka50
	call _strlength
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov dlina50, eax
	push strokachislo50
	call _strtransint
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov strchislo50, eax

push offset copystr50
call soutl

push dlina50
call noutl

push strchislo50
call noutl
	push short37
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i50, eax
cycle1:
	mov eax, i50
	cmp eax, short38
	jge cycleEnd1

push i50
call noutl
	push i50
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
	mov i50, eax
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