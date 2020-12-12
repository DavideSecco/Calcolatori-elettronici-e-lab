.586
.model flat
.code


_somma_modulo proc
push ebp
mov ebp, esp

sub esp, 8
push esi
push edi
push ebx

call inizializzazione

call div_vettore

call somma_resti

pop ebx
pop edi
pop esi

mov esp, ebp
pop ebp
ret

_somma_modulo endp

inizializzazione proc

mov ebx, [ebp + 8]		;in ebx <- vettore dei dividendi
mov ecx, [ebp + 16]		;in ecx <- vettore dei resti
						; in [ebp+12] <- lunghezza
						; in [ebp+20] <- divisore

mov esi, 0				; esi sarà il contatore

inizializzazione endp

div_vettore proc

ciclo_1:
	cmp esi, [ebp+12]
	je fine_1					;controllo di non essere arrivato a fine vettore

	mov eax, [ebx+esi*4]
	CDQ
	idiv dword ptr[ebp+20]		; divido

	mov [ecx +4*esi], edx		;scrivo il resto nel vettore dst
	inc esi						
	jmp ciclo_1

fine_1:
	ret


div_vettore endp

somma_resti proc

mov esi, 0
mov eax, 0

ciclo_2:
	cmp esi, [ebp+12]
	je fine_2	
	add eax, [ecx+4*esi]
	inc esi
	jmp ciclo_2

fine_2:
	ret

somma_resti endp

end