.586
.model flat
.code

_conta_occorrenze proc 

push ebp 
mov ebp, esp
push ebx
push esi
push edi

mov ebx, dword ptr[ebp+8]			;stringa in cui contare le occorrenze
mov ecx, dword ptr[ebp+12]			;stringa della parola
mov edx, 0
mov edi, 0							;fa da contatore

call _ciclo

pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret

_conta_occorrenze endp



_ciclo proc

ciclo_1:
	mov al, byte ptr[ebx + edi]
	cmp al, 0
	je fine

	mov ah, byte ptr[ecx]
	cmp ah, al
	je occorrenza
	ritorno:
	inc edi

jmp ciclo_1


fine:
	mov eax, edx
	ret


occorrenza:

mov esi, 0

ciclo_2:
	mov ah, byte ptr[ecx + esi]
	mov al, byte ptr[ebx + edi]
	cmp ah, 0
	je ce_parola
	cmp al, 0
	je non_ce_occorrenza
	cmp ah, al
	jne non_ce_occorrenza
	inc edi
	inc esi
	jmp ciclo_2

ce_parola:
	cmp al,' '
	jne non_ce_occorrenza
	push edi
	mov edi, esi
	dec edi
	mov al, byte ptr[ebx + edi]
	cmp al,' '
	jne non_ce_occorrenza
	pop edi
	inc edx

non_ce_occorrenza:
	jmp ritorno

_ciclo endp
end
