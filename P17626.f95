program P17626
    implicit none
    integer :: n, i, j, sq
    integer, dimension(0:50000) :: save
    read *, n
    save(0) = 0
    do i = 1, n
        save(i) = i
        j = 1
        sq = 1
        do while (sq <= i)
            save(i) = min(save(i), save(i - sq) + 1)
            j = j + 1
            sq = j * j
        end do
    end do
    write (*, '(I0)') save(n)
end program P17626