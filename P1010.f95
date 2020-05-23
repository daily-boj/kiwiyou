program P1010
    implicit none
    integer :: cases, i
    integer :: west, east, j, k
    integer, dimension(30, 30) :: count
    do i = 1, 30
        count(1, i) = i
    end do
    read *, cases
    do i = 1, cases
        read *, west, east
        do j = 2, west
            count(j, j - 1) = 0
            do k = j, east
                count(j, k) = count(j - 1, k - 1) + count(j, k - 1)
            end do
        end do
        write (*, '(I0)') count(west, east)
    end do
end program P1010