program P17247
    implicit none

    integer, dimension(1000) :: row
    integer :: ax, ay, bx, by
    logical :: a_found
    integer :: i, j, width, height

    read (*, *) height, width

    a_found = .FALSE.
    do i = 1, height
        read (*, *) (row(j), j = 1, width)
        do j = 1, width
            if (row(j) == 1) then
                if (a_found) then
                    bx = j
                    by = i
                else
                    ax = j
                    ay = i
                    a_found = .TRUE.
                end if
            end if
        end do
    end do

    write (*, '(I0)') (abs(ax - bx) + abs(ay - by))
end program P17247