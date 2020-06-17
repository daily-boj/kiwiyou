program P2410
    implicit none
    integer :: n, i, gap = 1
    integer, dimension(0:1000000) :: save
    read *, n
    save(0) = 1
    do while (gap <= n)
        do i = gap, n
            save(i) = mod(save(i) + save(i - gap), 1000000000)
        end do
        gap = lshift(gap, 1)
    end do
    write (*, '(I0)') save(n)
end program P2410