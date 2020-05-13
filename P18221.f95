program P18221
    implicit none
    integer :: size, i, j, sungyu_x, sungyu_y, gyosu_x, gyosu_y, top, left, bottom, right, barrier
    integer, dimension(1000, 1000) :: room
    read *, size
    do i = 1, size
        read *, (room(i, j), j = 1, size)
    end do
    do i = 1, size
        do j = 1, size
            if (room(i, j) == 2) then
                sungyu_x = i
                sungyu_y = j
            else if (room(i, j) == 5) then
                gyosu_x = i
                gyosu_y = j
            end if
        end do
    end do
    left = min(sungyu_x, gyosu_x)
    right = max(sungyu_x, gyosu_x)
    top = min(sungyu_y, gyosu_y)
    bottom = max(sungyu_y, gyosu_y)
    barrier = 0
    do i = left, right
        do j = top, bottom
            if (room(i, j) == 1) then
                barrier = barrier + 1
            end if
        end do
    end do
    if (((sungyu_x - gyosu_x) ** 2 + (sungyu_y - gyosu_y) ** 2) >= 25 .and. barrier >= 3) then
        write (*, '(I0)') 1
    else
        write (*, '(I0)') 0
    end if
end program P18221