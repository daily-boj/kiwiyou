program P16478
    implicit none
    integer :: ab, bc, cd
    read *, ab, bc, cd
    write (*, '(F0.7)') real(ab * cd) / real(bc)
end program P16478