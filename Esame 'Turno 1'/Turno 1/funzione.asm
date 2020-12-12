.586
.model flat
.code

_divisione_array proc

push ebp
mov ebp, esp

sub esp, 8
push esi
push edi
push ebx

call inizio

call ciclo

call controllo

pop esi
pop edi
pop ebx

mov esp, ebp
pop ebp
ret

_divisione_array endp

inizio proc

mov ebx, dword ptr[ebp+8]			;metto in ebx indirizzo vettore
mov esi, 0							;esi lo metto come contatore
mov ecx, dword ptr[ebp+20]			;metto in ecx indirizzo resto
									;il divisore del vettore		 dword ptr[ebp+12]
									;la lunghezza del vettore		dowrd ptr[ebp+16]


ret

inizio endp

ciclo proc

ciclo_1:
	cmp esi, dword ptr[ebp + 16]
	je fine
	mov eax, [ebx + 4*esi]
	CDQ
	idiv dword ptr[ebp+12]
	mov [ebx + 4*esi], eax
	mov [ecx + 4*esi], edx
	inc esi
	jmp ciclo_1

fine:
	ret

ciclo endp

controllo proc

mov esi, 0

mov eax, dword ptr[ecx]
cmp eax, 0
je resto_uguale_0
jne resto_diverso_0

ret	

controllo endp

resto_uguale_0 proc

mov eax, -1
mov ebx, dword ptr[ebp + 16]

ciclo_2:
	cmp esi, dword ptr[ebp + 16]
	je fine_2
	mov ebx, [ecx + 4*esi]
	cmp ebx, 0
	jne non_e_0
	inc esi
	jmp ciclo_2

non_e_0:
	mov eax, 0
fine_2:
	ret

resto_uguale_0 endp

resto_diverso_0 proc

mov eax, +1

ciclo_2:
	cmp esi, dword ptr[ebp + 16]
	je fine_3
	mov ebx, [ecx + 4*esi]
	cmp ebx, 0
	je e_0
	inc esi
	jmp ciclo_2

e_0:
	mov eax, 0
fine_3:
	ret

resto_diverso_0 endp

end