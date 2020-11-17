.586
.model flat
.code

_primo proc 

push ebp 
mov ebp, esp
push ebx
push esi
push edi

mov esi, 0							;scorre i vettori
mov ebx, dword ptr[ebp+8]			;indirizzo di a
mov edi, dword ptr[ebp+12]			;indirizzo di b
mov ecx, 0							;deve contare i numeri primi

ciclo:
cmp esi, dword ptr[ebp+16]			;sono arrivato alla fine del vettore
je fine_ciclo						;ho finito


mov eax, dword ptr [ebx+esi*4]		;metto in eax il numero
push eax							;metto in [ebp-16] il numero
push esi							;metto in [ebp-20] il contatore
mov esi, eax						
sub esi, 1							;esi <- (eax - 1) (così passo il valore di eax-1 alla funzione)

call _numero_primo

pop esi
pop eax
inc esi								;incremento il contatore
jmp ciclo							;torno all'inizio

fine_ciclo:

mov eax, ecx
pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret

_primo endp



_numero_primo proc

ciclo_2:
cmp esi,1
je e_primo

mov eax, dword ptr [ebp-16]
cdq
idiv esi
cmp edx, 0

je non_e_primo
sub esi, 1
jmp ciclo_2

e_primo:
inc ecx
mov esi, dword ptr [ebp-20]
mov dword ptr[edi+esi*4], 1

non_e_primo:
ret

_numero_primo endp

end
