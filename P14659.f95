program P14659
    implicit none
    integer :: count, max_height, church, max_church, i
    integer, dimension(30000) :: heights
    read *, count
    read *, (heights(i), i = 1, count)
    max_height = 0
    max_church = 0
    church = 0
    do i = 1, count
        if (heights(i) >= max_height) then
            max_church = max(max_church, church)
            church = 0
            max_height = heights(i)
        else
            church = church + 1
        end if
    end do
    max_church = max(max_church, church)
    write (*, '(I0)') max_church
end program P14659