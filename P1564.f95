program P1564
    implicit none
    integer :: n
    integer(16) :: i, j
    integer(16) :: fact
    integer(16) :: modulo

    modulo = 1000000
    modulo = modulo * 1000000

    read *, n
    fact = 36288
    do i = 11, n
        j = i
        fact = fact * j
        do while (mod(fact, 10) == 0)
            fact = fact / 10
        end do
        fact = mod(fact, modulo);
    end do
    write (*, '(I0.5)') mod(fact, 100000)
end program P1564