import serial as sr 
import tkinter as tk


def on(): #Fungsi saat tombol "on" ditekan
        s.write(b'a') # Mengirim karakter "a" ke arduino
def off(): #Fungsi saat tombol "off" ditekan 
        s.write(b'b') # Mengirim karakter "b" ke arduino

#-----Kode utama GUI-----
root = tk.Tk()
root.title('Kontrol Lampu')
root.configure(background = 'blue')
root.geometry("180x180") # Seting ukuran tampilan

#-----Membuat Tombol-----
root.update();
menyala = tk.Button(root, text = "Nyala", font = ('calbiri',12),command = lambda: on(),bg="yellow")
menyala.place(x = 20, y = 20)

root.update();
padam = tk.Button(root, text = "Padam", font = ('calbiri',12),command = lambda: off(),bg="yellow")
padam.place(x = menyala.winfo_x() + menyala.winfo_reqwidth() + 20, y = 20)

#-----Memulai seting port serial-----
s = sr.Serial('COM4', 9600);

root.mainloop()
