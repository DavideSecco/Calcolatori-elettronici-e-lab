.586
.model flat
.code

_atoi proc
 push ebp
 mov ebp, esp

sub esp, 8
push esi
push edi
push ebx

mov ebx, dword ptr[ebp+8]
mov esi, 0					;conta i numeri
mov edi, 1					;esponente
mov ecx, 0					;numero finale

call conta_numeri

sub esi, 2

call numero

mov eax, ecx

pop ebx
pop edi
pop esi

mov esp, ebp
pop ebp
ret
_atoi endp


conta_numeri proc

ciclo:
	mov al, byte ptr[ebx + esi]
	inc esi
	cmp al, 0
	jne ciclo

ret

conta_numeri endp

numero proc

ciclo_2:
	cmp esi, -1
	je fine_2
	mov eax, 0
	mov al, byte ptr[ebx + esi]
	sub al, 48
	mul edi
	add ecx, eax

	mov eax, edi				;metto il vecchio esponente in eax
	mov edi, 10					;moltiplico per 10
	mul edi						;ho il nuovo esponente in eax
	mov edi, eax				;rimetto l'esponente in eax
	
	dec esi
	jmp ciclo_2

fine_2:
	ret

numero endp

end