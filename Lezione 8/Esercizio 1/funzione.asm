.586
.model flat
.code

_palindromo proc 

push ebp 
mov ebp, esp
push ebx
push esi
push edi

mov ebx, dword ptr[ebp+8]			;dovrebbe esserci indirizzo del vettore
mov edi, 0							;fa da contatore

call _lunghezza


mov esi, 0							;in esi <- 0 (in edi la lunghezza)

call _pal


fine_ciclo:


pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret

_palindromo endp



_lunghezza proc

ciclo_1:
mov al, byte ptr[ebx + edi]
cmp al, 0
je fine_1
inc edi
jmp ciclo_1

fine_1:
dec edi

ret

_lunghezza endp



_pal proc

ciclo_2:
cmp edi, esi
je sono_palindromi
jna sono_palindromi					

mov al, byte ptr[ebx+esi]
mov cl, byte ptr[ebx+edi]
cmp al, cl
jne non_sono_palindromi

inc esi
dec edi

jmp ciclo_2

sono_palindromi: 
mov eax, 1
jmp fine_2

non_sono_palindromi:
mov eax, 0


fine_2:
ret

_pal endp

end
