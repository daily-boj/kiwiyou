program P2293
    implicit none
    integer :: kinds, target, coin, i, j
    integer, dimension(0:10000) :: count
    read *, kinds, target
    do i = 0, target
        count(i) = 0
    end do
    count(0) = 1
    do i = 1, kinds
        read *, coin
        do j = coin, target
            count(j) = count(j) + count(j - coin)
        end do
    end do
    write (*, '(I0)') count(target)
end program P2293