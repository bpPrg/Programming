!Author: Bhishan Poudel
!Program: File input output
!cmd    : clear; gfortran fileWriteRead.f90 && ./a.out

program outputdata   
implicit none   

   real, dimension(100) :: x, y  
   real, dimension(100) :: p, q
   integer :: i  
   
   ! data  
   do i=1,10  
      x(i) = i * 0.1 
      y(i) = sin(x(i)) * (1-cos(x(i)/3.0))  
   end do  
   
   ! output data into a file 
   open(1, file='data1.dat', status='unknown')  ! status = replace will create new file if it doesnot exist
   do i=1,10  
      write(1,*) x(i), y(i)   
   end do  
   close(1) 

   ! opening the file for reading
   open (2, file='data1.dat', status='unknown')

   do i=1,10  
      read(2,*) p(i), q(i)
   end do 
   
   close(2)
   
   do i=1,10  
      write(*,*) p(i), q(i)
   end do 
   
end program outputdata



