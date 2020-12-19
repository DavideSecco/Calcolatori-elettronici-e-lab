.586
.model flat
.code

_cerca_combinazioni_numero proc
push ebp
mov ebp,esp

sub esp, 8
push esi
push edi
push ebx

call inizializzazione

call ciclo

mov eax, 0

pop ebx
pop edi
pop esi

mov esp, ebp
pop ebp
ret

_cerca_combinazioni_numero endp

inizializzazione proc

mov ebx,dword ptr[ebp+8]		;salvo src
mov ecx,dword ptr[ebp+16]		;salvo il vettore dove devo saltare
								;in [ebp+12] c'è il numero da trovare

mov dword ptr[ecx+0], 0
mov dword ptr[ecx+4], 0
mov dword ptr[ecx+8], 0			;azzero il vettore di destinazione

ret

inizializzazione endp

ciclo proc

mov edi, 0

ciclo_1:
	mov eax, 0
	mov al, byte ptr[ebx+edi]
	cmp al, 0
	je fine_1
	sub al, 48
	cmp eax, dword ptr[ebp+12]
	je trovato
return_1:
	inc edi
	jmp ciclo_1

trovato: 
	call find
	jmp ciclo_1						;!!!!occhio qui!!!

fine_1:
	ret

ciclo endp

find proc

mov esi, 0				;conta quante volte c'è quel carattere

ciclo_2:
	inc edi
	mov eax, 0
	mov al, byte ptr[ebx+edi]
	cmp al, 0
	je fine_2

	sub al, 48
	cmp eax, dword ptr[ebp+12]
	jne fine_2

	inc esi
	cmp esi, 3
	je fine_2
	jmp ciclo_2

fine_2:
	inc dword ptr[ecx+4*esi]
	ret	

find endp

end