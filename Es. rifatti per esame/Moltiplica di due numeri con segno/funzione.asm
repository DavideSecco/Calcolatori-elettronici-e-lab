.586      
.model flat      
.code   	

_moltiplica_con_segno proc 	
push ebp 
mov ebp, esp
push ebx
push esi
push edi

mov ecx, dword ptr[ebp + 8]			;salvo a
mov edx, dword ptr[ebp + 12]		;salvo b
mov edi, 0							;per il segno della moltiplicazione
mov esi, 0							;risultato della moltiplicazione

call _cambia_segni

call _moltiplicazione

cmp edi, 1
jne fine
neg esi

fine:
mov eax, esi

pop edi
pop esi
pop ebx
mov esp, ebp
pop ebp
ret

_moltiplica_con_segno endp	

_cambia_segni proc

cmp ecx, 0
jl cambia_segno_1
ret1:

cmp edx, 0
jl cambia_segno_2
ret2:

ret

cambia_segno_1:
neg ecx
inc edi
jmp ret1

cambia_segno_2:
neg edx
inc edi
jmp ret2

_cambia_segni endp

_moltiplicazione proc

ciclo:
cmp edx, 0
je fine_molt
add esi, ecx
dec edx
jmp ciclo

fine_molt:
ret

_moltiplicazione endp

End				
