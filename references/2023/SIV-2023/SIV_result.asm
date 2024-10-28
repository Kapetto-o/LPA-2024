.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib

ExitProcess PROTO:DWORD 
SYSPAUSE PROTO 
soutl PROTO : BYTE 
noutl PROTO : SDWORD 
_pow PROTO  : SDWORD, : SDWORD 
_abs PROTO  : SDWORD 

.STACK 4096

.CONST
	null_division BYTE 'ERROR: DIVISION BY ZERO', 0
	OVER_FLOW BYTE 'ERROR: OVERFLOW', 0
	true BYTE 'true', 0
	false BYTE 'false', 0
	short0 SDWORD -1
	short1 SDWORD 0
	str2 BYTE "Hello there!", 0
	str3 BYTE "�����. ��������:", 0
	short4 SDWORD 26
	short5 SDWORD 13
	str6 BYTE "����������� ������ ���������: ", 0
	short7 SDWORD 5
	short8 SDWORD 11
	short9 SDWORD 2
	short10 SDWORD 178
	short11 SDWORD 19
	short12 SDWORD 255
	short13 SDWORD 19
	str14 BYTE "FFH + 23O = ", 0
	str15 BYTE "����� �������:", 0
	short16 SDWORD -4
	short17 SDWORD 3
	str18 BYTE "�������� ��������:", 0
	short19 SDWORD 0
	str20 BYTE "positive", 0
	short21 SDWORD 1
	str22 BYTE "negative", 0
	short23 SDWORD -1
	bool24 DWORD 1
	str25 BYTE "Its true", 0
	str26 BYTE "Its false", 0
.DATA
	res10 SDWORD 0
	str163 DWORD ?
	i63 SDWORD 0
	num63 SDWORD 0
	c63 SDWORD 0
	flag63 DWORD 0

.CODE

func1 PROC b1 : SDWORD, a1 : SDWORD
	push short0
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov res10, eax
	mov eax, a1
	cmp eax, short1
	jl ifi1
	jge else1
ifi1:
	push a1
	call _abs
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov res10, eax
	jmp ifEnd1
else1:
	push a1
	push b1
	call _pow
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov res10, eax
ifEnd1:
	push res10
	jmp local0
local0:
	pop eax
	ret
func1 ENDP

setstring2 PROC s2 : DWORD
	push s2
	jmp local1
local1:
	pop eax
	ret
setstring2 ENDP

main PROC
	push offset str2
	call setstring2
	push eax
	pop str163


push str163
call soutl

push offset str3
call soutl
	push short4
	push short5
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
	mov i63, eax

push i63
call noutl

push offset str6
call soutl
	push short7
	push short8
	push short9
	call _pow
	push eax
	push short10
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop eax
	pop ebx
	mul ebx
	push eax
	push short11
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i63, eax

push i63
call noutl
	push short12
	push short13
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov i63, eax

push offset str14
call soutl

push i63
call noutl

push offset str15
call soutl
	push short16
	push short17
	call func1
	push eax
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov num63, eax

push num63
call noutl

push offset str18
call soutl
	mov eax, i63
	cmp eax, short19
	jge ifi2
	jl else2
ifi2:

push offset str20
call soutl
	push short21
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov c63, eax
	jmp ifEnd2
else2:

push offset str22
call soutl
	push short23
	pop eax
	cmp eax, 32767
	jg overflow
	cmp eax, -32768
	jl overflow
	mov c63, eax
ifEnd2:

push c63
call noutl
	mov eax, flag63
	cmp eax, bool24
	jz ifi3
	jnz else3
ifi3:

push offset str25
call soutl
	jmp ifEnd3
else3:

push offset str26
call soutl
ifEnd3:
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