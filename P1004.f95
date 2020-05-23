function inside_circle(cen_x, cen_y, radius, x, y) result(is_inside)
    implicit none
    integer, intent(in) :: cen_x, cen_y, radius, x, y
    integer :: distance
    logical :: is_inside
    distance = (cen_x - x) * (cen_x - x) + (cen_y - y) * (cen_y - y)
    is_inside = distance < radius * radius
end function inside_circle

program P1004
    implicit none
    integer :: cases, i
    integer :: src_x, src_y, dst_x, dst_y
    integer :: systems, j
    integer :: cen_x, cen_y, radius
    integer :: io
    logical :: src_inside, dst_inside
    logical :: inside_circle
    read *, cases
    do i = 1, cases
        read *, src_x, src_y, dst_x, dst_y
        read *, systems
        io = 0
        do j = 1, systems
            read *, cen_x, cen_y, radius
            src_inside = inside_circle(cen_x, cen_y, radius, src_x, src_y)
            dst_inside = inside_circle(cen_x, cen_y, radius, dst_x, dst_y)
            if (src_inside .neqv. dst_inside) then
                io = io + 1
            end if
        end do
        write (*, '(I0)') io
    end do
end program P1004