.386
.model flat, stdcall
.stack 4096

includelib kernel32.lib
includelib user32.lib  ; ��� ������������� MessageBoxA

ExitProcess PROTO :DWORD
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD
WriteConsoleA PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD
GetStdHandle PROTO :DWORD

.data
    message1 db "���� ������:", 0
    message2 db "�������������� ��������:", 0
    message3 db "����� �������:", 0
    message4 db "����:", 0
    msgBoxText db "Hello, world!", 0
    msgBoxTitle db "Message Box", 0

    parm1 db "TestText1", 0
    parm2 db "TestText20", 0
    stroka db "�������� �������", 0
    strokachislo db "125", 0
    copystr db 256 dup(0)

    hConsoleOutput dd 0   ; ����� �������

.code

; ������� testfunc1: int testfunc1(int a, int b) {
;     return a + b;
; }
_testfunc1 proc
    push ebp
    mov ebp, esp
    mov eax, [ebp+8] ; a
    add eax, [ebp+12] ; b
    pop ebp
    ret
_testfunc1 endp

; ������� testfunc2: str testfunc2(str parm1) {
;     strduplicate(parm1, parm2);
;     return parm1;
; }
_testfunc2 proc
    push ebp
    mov ebp, esp
    lea eax, parm1
    lea edx, parm2
    ; ������� ����������� ����� ������ � ������
    mov ecx, 0
_copy_string:
    mov al, [edx+ecx]
    mov [eax+ecx], al
    inc ecx
    test al, al
    jnz _copy_string
    mov eax, offset parm1
    pop ebp
    ret
_testfunc2 endp

; ������� testfunc3: char testfunc3(char simbol) {
;     cycle (i < 10) { write simbol; }
; }
_testfunc3 proc
    push ebp
    mov ebp, esp
    sub esp, 4 ; �������� ����� ��� i
    mov dword ptr [ebp-4], 0 ; i = 0

_cycle_start:
    cmp dword ptr [ebp-4], 10 ; i < 10 ?
    jge _cycle_end

    ; ���������� ������ � �������
    mov eax, 1        ; ���������� ��������
    lea edx, [ebp+8]  ; ����� �������
    invoke WriteConsoleA, hConsoleOutput, edx, eax, 0, 0

    inc dword ptr [ebp-4] ; i++
    jmp _cycle_start

_cycle_end:
    add esp, 4 ; ������� i
    pop ebp
    ret
_testfunc3 endp

; �������� ������� main
_main proc
    ; �������� ����� �������
    invoke GetStdHandle, -11
    mov [hConsoleOutput], eax

    ; ���� ������
    invoke MessageBoxA, 0, offset message1, offset msgBoxTitle, 0

    ; �������������� ��������
    invoke MessageBoxA, 0, offset message2, offset msgBoxTitle, 0

    ; ����� �������
    invoke MessageBoxA, 0, offset message3, offset msgBoxTitle, 0

    ; ����
    invoke MessageBoxA, 0, offset message4, offset msgBoxTitle, 0

    ; ���������� ���������
    invoke ExitProcess, 0
_main endp

end _main
