.586
.model flat
.code

_numeri_pari proc
push ebp
mov ebp, esp

push esi
push edi
push ebx

mov ebx, dword ptr[ebp + 8]			;salvo l'indirizzo del vettore
mov ecx, 2
mov edi, 0							;scorro il vettore
mov esi, 0							;conto i numeri pari

ciclo: 
cmp edi, dword ptr[ebp + 12]
je fine
call _pari
inc edi

jmp ciclo


fine:
mov eax, esi

pop ebx
pop edi
pop ebx

pop ebp
ret

_numeri_pari endp

_pari proc
mov eax, dword ptr[ebx + 4*edi]
mov edx, 0
div ecx
cmp edx, 0
jne fine_pari

inc esi

fine_pari:
ret

_pari endp
end