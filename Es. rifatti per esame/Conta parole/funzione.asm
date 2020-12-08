.586
.model flat
.code

_conta_parole proc

push ebp
mov ebp, esp

sub esp, 8

push esi
push edi
push ebx

mov ebx, dword ptr[ebp + 8]
mov esi, 0						;mi sposto per la stringa
mov edi, 0						;contatore per le parole

Ciclo:
mov al, byte ptr[ebx + esi]
cmp al, 0
je fine
cmp al," "
je salta_spazi
jne salta_parola
return:
jmp ciclo

salta_spazi:
call _spazi
jmp return

salta_parola:
call _parola
jmp return


fine:
mov eax, edi

pop ebx
pop edi
pop esi

mov esp, ebp
pop ebp

ret

_conta_parole endp

_spazi proc

ciclo_2:
inc esi
mov al, byte ptr[ebx + esi]
cmp al, 0
je fine_2
cmp al," "
je ciclo_2

fine_2:
ret

_spazi endp

_parola proc

inc edi

ciclo_3:
inc esi
mov al, byte ptr[ebx + esi]
cmp al, 0
je fine_3
cmp al," "
jne ciclo_3


fine_3:
ret

_parola endp

end