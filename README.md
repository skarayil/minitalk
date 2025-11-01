# 📡 Minitalk - Unix Sinyaller ile İletişim Programı

<div align="center">

![42 School](https://img.shields.io/badge/School-42-black?style=for-the-badge&logo=42)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Minitalk](https://img.shields.io/badge/Project-minitalk-blue?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

**Unix sinyallerini kullanarak iki süreç arasında veri iletişimi sağlayan client-server sistemi**

*Bu proje, düşük seviyeli sistem programlama ve süreçler arası iletişim (IPC) konularında derinlemesine deneyim kazandırırken, Unix sinyallerinin gücünü ve esnekliğini keşfetme fırsatı sunar.*

[Kurulum](#-kurulum) • [Kullanım](#-kullanım) • [Özellikler](#-desteklenen-özellikler) • [Bonus](#-bonus-kısmı)

</div>

---

## 🎯 Projenin Amacı

<img align="right" alt="Signal Communication Animation" width="300" src="https://media3.giphy.com/media/v1.Y2lkPTc5MGI3NjExZjFweGVuaTZiY2h0cjczNjVuZDZyc2s5a3d3dWVieDVubHkzcDQzcyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/kl5ctZSctCbE4/giphy.gif">

Bu proje, **Unix sinyallerini kullanarak client-server mimarisi** ile iki süreç arasında veri iletişimi kurma amacı taşır. Proje, sistem programlamanın temel kavramlarını öğretir:

### 🎓 **Ana Öğrenme Hedefleri:**

#### 📡 **Unix Signal Handling**
- `SIGUSR1` ve `SIGUSR2` sinyallerini kullanarak binary data transmission
- Signal handler fonksiyonları ve asenkron sinyal işleme
- `kill()`, `signal()`, `sigaction()` sistem çağrıları

#### 🖥️ **Süreçler Arası İletişim (IPC)**
- Process ID (PID) kullanarak hedef süreç belirleme
- Client-server mimarisinde güvenli veri aktarımı
- Inter-process communication patterns ve best practices

#### 🔢 **Binary Data Encoding**
- ASCII karakterlerin bit seviyesinde işlenmesi
- Bit manipulation ve binary encoding/decoding
- Karakter verilerinin sinyal dizisine dönüştürülmesi

#### ⏱️ **Asenkron Programlama**
- Non-blocking signal handling ve event-driven programming
- Race condition'ları önleme ve timing management
- Signal acknowledgment ve handshaking protocols

#### 🏗️ **System-Level Programming**
- Low-level system programming concepts
- Process lifecycle management ve resource handling
- Error handling ve robust system design

#### 🛡️ **Concurrency ve Synchronization**
- Multiple client handling (bonus)
- Thread safety ve signal safety considerations
- Critical section management ve data integrity

---

## ✨ Desteklenen Özellikler

<div align="center">

![Signal Communication](https://img.shields.io/badge/Signal-Communication-brightgreen?style=for-the-badge)
![Binary Encoding](https://img.shields.io/badge/Binary-Encoding-blue?style=for-the-badge)
![Client Server](https://img.shields.io/badge/Client-Server-orange?style=for-the-badge)

</div>

### 📋 **Ana Fonksiyonalite**

| Component | Sorumluluk | İletişim Yöntemi |
|-----------|------------|-------------------|
| **Server** | Sinyal dinleme ve mesaj alma | `SIGUSR1`/`SIGUSR2` reception |
| **Client** | Mesaj gönderme | `SIGUSR1`/`SIGUSR2` transmission |
| **Encoding** | Karakter → Binary dönüşümü | Bit manipulation |
| **Decoding** | Binary → Karakter dönüşümü | Signal reconstruction |

### 🔧 **Çalışma Prensibi**

```
Client Process                    Server Process
      ↓                                ↓
   Message                        Signal Handler
      ↓                                ↓
Binary Encoding         ←→       Binary Decoding
      ↓                                ↓
SIGUSR1/SIGUSR2        ←→       Character Output
   (1 bit/signal)                     ↓
                                 Message Display
```

#### 📊 **Signal Encoding Tablosu**

| Bit Value | Signal | Açıklama |
|-----------|--------|----------|
| **1** | `SIGUSR1` | Binary 1 değeri |
| **0** | `SIGUSR2` | Binary 0 değeri |

#### 🔄 **Mesaj Aktarım Süreci**

1. **Client**: Mesajı karakter karakter işler
2. **Bit Extraction**: Her karakteri 8 bit'e ayırır
3. **Signal Transmission**: Her bit için sinyal gönderir
4. **Server Reception**: Sinyalleri yakalar ve birleştirir
5. **Character Reconstruction**: 8 bit → ASCII karakter
6. **Message Display**: Tam mesajı ekrana yazdırır

---

## 🎁 Bonus Kısmı

<div align="center">

![Acknowledgment](https://img.shields.io/badge/Acknowledgment-Protocol-gold?style=for-the-badge)
![Multiple Clients](https://img.shields.io/badge/Multiple-Clients-purple?style=for-the-badge)

</div>

Bonus kısmı, iletişimi daha güvenli ve verimli hale getiren gelişmiş özellikler sunar:

### 🔄 **Acknowledgment Protocol**

| Özellik | Açıklama | Avantaj |
|---------|----------|---------|
| **Signal Confirmation** | Her sinyal için onay mekanizması | Data integrity |
| **Handshaking** | Client-server senkronizasyonu | Reliable transmission |
| **Error Recovery** | Başarısız iletim yeniden deneme | Fault tolerance |

### 📊 **Gelişmiş İletişim Özellikleri**

#### 🎯 **Çoklu İstemci Desteği**
- Farklı PID'lerden gelen mesajları ayırt etme
- Concurrent client handling ve message queuing
- Client state management ve isolation

#### 📈 **İstatistik ve Monitoring**
- Gönderilen byte sayısının takibi
- İletim başarı oranı monitoring
- Performance metrics ve timing analysis

#### 🛡️ **Gelişmiş Hata Yönetimi**
- Invalid PID detection ve handling
- Signal delivery failure recovery
- Comprehensive error reporting

#### 🎨 **Görsel Geliştirmeler**
- Colorful terminal output
- Progress indicators ve status messages
- User-friendly interface design

---

## 📁 Dosya Yapısı

```
minitalk/
│
├── 📄 Makefile                     # Build automation ve derleme kuralları
├── 🌐 server.c                     # Server implementasyonu
├── 📱 client.c                     # Client implementasyonu  
├── 🔧 utils.c                      # Yardımcı fonksiyonlar
├── 📋 minitalk.h                   # Header dosyası ve tanımlamalar
│
├── 🎁 Bonus Files:
├── 🌐 server_bonus.c               # Gelişmiş server (ACK protocol)
├── 📱 client_bonus.c               # Gelişmiş client (ACK handling)
├── 🔧 utils_bonus.c                # Bonus yardımcı fonksiyonlar
├── 📋 minitalk_bonus.h             # Bonus header dosyası
└── 📖 README.md                    # Proje dokümantasyonu
```

### 📊 **Dosya Açıklamaları**

| Dosya | İçerik | Sorumluluk |
|-------|--------|------------|
| `server.c` | Ana server logic | Signal handling, message reconstruction |
| `client.c` | Ana client logic | Message encoding, signal transmission |
| `utils.c` | Helper functions | String utilities, number conversion |
| `minitalk.h` | Header definitions | Function prototypes, constants |
| `*_bonus.c` | Enhanced features | ACK protocol, multi-client support |

---

## 🚀 Kurulum

### 📋 **Ön Gereksinimler**

![GCC](https://img.shields.io/badge/GCC-Required-red?style=flat-square&logo=gnu&logoColor=white)
![Make](https://img.shields.io/badge/Make-Required-blue?style=flat-square&logo=gnu&logoColor=white)
![Unix](https://img.shields.io/badge/Unix-Compatible-green?style=flat-square&logo=linux&logoColor=white)

- **C Compiler**: `gcc` veya `clang`
- **Unix-like System**: Linux, macOS, WSL
- **Process Management**: PID access ve signal handling desteği

### 📥 **Repository Klonlama**

```bash
# Projeyi yerel sisteminize klonlayın
git clone https://github.com/skarayil/minitalk.git
cd minitalk
```

### 🔨 **Derleme İşlemi**

```bash
# Temel versiyonu derle
make

# Bonus versiyonu derle
make bonus

# Temizlik işlemleri
make clean          # Object dosyalarını sil
make fclean         # Tüm oluşturulan dosyaları sil
make re             # Yeniden derle (fclean + make)
```

### 📦 **Çıktı Dosyaları**

```bash
server              # Server executable
client              # Client executable
server_bonus        # Enhanced server (bonus)
client_bonus        # Enhanced client (bonus)
```

---

## 💻 Kullanım

### 🖥️ **Temel Kullanım**

#### 🟢 **1. Server'ı Başlatma**

```bash
# Terminal 1'de server'ı başlat
./server

# Çıktı:
# Server PID: 12345
```

#### 🟡 **2. Client ile Mesaj Gönderme**

```bash
# Terminal 2'de client ile mesaj gönder
./client 12345 "Merhaba, Minitalk!"

# Server terminal'inde görünür:
# Merhaba, Minitalk!
```

### 🎁 **Bonus Kullanım**

#### 🟣 **Acknowledgment Protocol ile İletişim**

```bash
# Terminal 1: Bonus server
./server_bonus

# Çıktı:
# ╔═════════════════════════╗
# ║  MINITALK BONUS SERVER  ║
# ╚═════════════════════════╝
# 
# Server PID: 12345
# Waiting for messages...

# Terminal 2: Bonus client
./client_bonus 12345 "Test mesajı"

# Client çıktısı:
# Client PID: 67890
# Server PID: 12345
# Sent Bytes: 12
# 
# Message delivered!

# Server çıktısı:
# Test mesajı
# 
# Message #1 received successfully!
# From Client PID: 67890
# ────────────────────────────────────
```

### 📝 **Kod Örnekleri**

#### 🟢 **Temel Server Implementasyonu**

```c
#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void ft_signal_handler(int signal)
{
    static int bit;
    static int byte;

    byte |= (signal == SIGUSR1) << bit;
    bit++;
    if (bit == 8)
    {
        ft_putchar_fd(byte, 1);
        if (byte == '\0')
            ft_putchar_fd('\n', 1);
        bit = 0;
        byte = 0;
    }
}

int main(void)
{
    ft_putstr_fd("Server PID: ", 1);
    ft_putnbr(getpid());
    ft_putchar_fd('\n', 1);
    
    signal(SIGUSR1, ft_signal_handler);
    signal(SIGUSR2, ft_signal_handler);
    
    while (1)
        pause();
    return (0);
}
```

#### 🟡 **Temel Client Implementasyonu**

```c
#include "minitalk.h"
#include <signal.h>
#include <unistd.h>

void ft_send_bit(int pid, int bit)
{
    if (bit == 1)
        kill(pid, SIGUSR1);
    else
        kill(pid, SIGUSR2);
    usleep(300);  // Timing delay
}

void ft_send_char(int pid, char c)
{
    int i = 0;
    
    while (i < 8)
    {
        ft_send_bit(pid, (c >> i) & 1);
        i++;
    }
}

void ft_send_string(int pid, char *str)
{
    while (*str)
    {
        ft_send_char(pid, *str);
        str++;
    }
    ft_send_char(pid, '\0');  // Null terminator
}

int main(int ac, char *av[])
{
    int pid;
    
    if (ac != 3)
    {
        ft_putstr_fd("Usage: ./client <PID> <message>\n", 2);
        return (1);
    }
    
    pid = ft_atoi(av[1]);
    if (kill(pid, 0) == -1 || pid <= 0)
    {
        ft_putstr_fd("Error: Invalid PID\n", 2);
        return (1);
    }
    
    ft_send_string(pid, av[2]);
    return (0);
}
```

#### 🔴 **Bonus: Acknowledgment Protocol**

```c
// Client tarafında ACK handling
volatile sig_atomic_t g_ack_received = 0;

void ft_ack_handler(int sig)
{
    (void)sig;
    g_ack_received = 1;
}

void ft_send_char_with_ack(int pid, char c)
{
    int bit = 8;
    
    while (bit--)
    {
        g_ack_received = 0;
        if ((c >> bit) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
            
        // ACK bekleme
        while (!g_ack_received)
            pause();
    }
}
```

---

## 🧪 Test Senaryoları

### ✅ **Temel Fonksiyonalite Testleri**

#### 📊 **Mesaj İletim Testleri**

```bash
# Kısa mesaj testi
./client [PID] "Hello"

# Uzun mesaj testi  
./client [PID] "Bu çok uzun bir mesaj testi. İçinde özel karakterler de var: !@#$%^&*()"

# Boş mesaj testi
./client [PID] ""

# Tek karakter testi
./client [PID] "A"
```

#### 🔤 **Özel Karakter Testleri**

```bash
# Unicode ve özel karakterler
./client [PID] "Türkçe karakterler: çğıöşü"

# ASCII kontrol karakterleri
./client [PID] "Tab:	Newline:\n"

# Sayısal karakterler
./client [PID] "Numbers: 0123456789"
```

### 🎁 **Bonus Testleri**

#### 🔄 **Acknowledgment Protocol Testleri**

```bash
# ACK protokolü ile güvenilir iletim
./client_bonus [PID] "Test ACK protocol"

# Büyük veri iletimi
./client_bonus [PID] "Very long message to test acknowledgment protocol reliability..."

# Çoklu client testi (paralel terminallerde)
./client_bonus [PID] "Client 1 message" &
./client_bonus [PID] "Client 2 message" &
./client_bonus [PID] "Client 3 message" &
```

### ⚠️ **Hata Durumu Testleri**

#### 🚫 **Invalid Input Testleri**

```bash
# Geçersiz PID
./client 99999 "Test message"           # Non-existent PID
./client -1 "Test message"              # Negative PID
./client abc "Test message"             # Non-numeric PID

# Eksik parametre
./client                                # No arguments
./client 12345                          # Missing message
```

#### 🛡️ **Signal Safety Testleri**

```bash
# Server interruptus testi
# Server çalışırken Ctrl+C ile kesme
# Memory leaks ve resource cleanup kontrolü

# Çoklu client race condition testi
for i in {1..10}; do
    ./client [PID] "Message $i" &
done
```

### 📈 **Performance Testleri**

#### ⚡ **Throughput Measurement**

```bash
# Büyük mesaj performans testi
time ./client [PID] "$(cat large_text_file.txt)"

# Çoklu mesaj timing
time {
    ./client [PID] "Message 1"
    ./client [PID] "Message 2"
    ./client [PID] "Message 3"
}
```

#### 🔍 **Memory Usage Analysis**

```bash
# Valgrind ile memory leak kontrolü
valgrind --leak-check=full ./server &
SERVER_PID=$!

valgrind --leak-check=full ./client $SERVER_PID "Test message"

kill $SERVER_PID
```

---

## 🛠️ Teknik Detaylar

### 🏗️ **Signal Handling Architecture**

```
Signal Flow:
│
├── Client Side:
│   ├── Message → Character Array
│   ├── Character → 8 Bits
│   ├── Bit → SIGUSR1/SIGUSR2
│   └── kill() → Target PID
│
└── Server Side:
    ├── Signal Handler Registration
    ├── SIGUSR1/SIGUSR2 → Bit Value
    ├── 8 Bits → Character
    └── Character → Output Stream
```

### 🔧 **Binary Encoding Schema**

#### 📊 **Bit Transmission Order**

```c
// Örnek: 'A' karakteri (ASCII 65 = 01000001)
Bit Position:  7 6 5 4 3 2 1 0
Binary Value:  0 1 0 0 0 0 0 1
Signal:        ↓ ↓ ↓ ↓ ↓ ↓ ↓ ↓
Transmission:  USR2 USR1 USR2 USR2 USR2 USR2 USR2 USR1

// Least Significant Bit (LSB) first transmission
```

#### 🔄 **Reconstruction Algorithm**

```c
void reconstruct_character(int signal_bit)
{
    static unsigned char character = 0;
    static int bit_position = 0;
    
    // Set bit based on signal
    if (signal_bit == SIGUSR1)
        character |= (1 << bit_position);
    
    bit_position++;
    
    if (bit_position == 8)
    {
        output_character(character);
        character = 0;
        bit_position = 0;
    }
}
```

### ⏱️ **Timing ve Synchronization**

#### 🕰️ **Signal Timing Management**

| Parameter | Value | Purpose |
|-----------|-------|---------|
| **SLEEP_TIME** | 300 µs | Inter-signal delay |
| **ACK_TIMEOUT** | 5 seconds | ACK wait timeout |
| **RETRY_COUNT** | 3 attempts | Failed signal retries |

#### 🔄 **Acknowledgment Protocol Flow**

```
Client                           Server
   ↓                               ↓
Send Signal          →        Receive Signal
   ↓                               ↓
Wait for ACK         ←        Process & Send ACK
   ↓                               ↓
Continue/Retry                 Continue Listening
```

### 📈 **Performance Characteristics**

| Metric | Value | Notes |
|--------|-------|-------|
| **Throughput** | ~8 signals/char | Plus timing delays |
| **Latency** | ~2.4ms/char | With 300µs delays |
| **Reliability** | 99.9%+ | With ACK protocol |
| **Concurrent Clients** | Multiple | Bonus feature |

---

## 📚 Notlar

### ⚠️ **Önemli Dikkat Edilmesi Gerekenler**

#### 🛡️ **Signal Safety**
- **Async-Signal-Safe Functions**: Signal handler'larda sadece güvenli fonksiyonlar kullanılmalı
- **Race Conditions**: Global değişkenler için `volatile sig_atomic_t` kullanımı
- **Signal Masking**: Critical section'larda signal blocking gerekebilir
- **Handler Interruption**: Signal handler'ların interrupt edilebileceği unutulmamalı

#### 🔧 **System Limitations**
- **Signal Queue Limits**: Sistem sinyal kuyruğu sınırlarına dikkat
- **PID Validation**: Hedef process'in existence kontrolü şart
- **Permission Checks**: Signal gönderme yetkilerinin kontrol edilmesi
- **Resource Cleanup**: Process termination'da resource temizleme

#### ⚡ **Performance Optimizations**
- **Signal Batching**: Mümkün olduğunda signal grouping
- **Timing Calibration**: System'a göre optimal delay ayarları
- **Memory Usage**: Minimal memory footprint için optimizasyon
- **CPU Efficiency**: Signal processing overhead minimization

### 💡 **Best Practices**

#### 🎯 **Robust Design:**
1. **Error Handling**: Comprehensive error checking her seviyede
2. **Signal Masking**: Critical sections'da signal safety
3. **Resource Management**: Proper cleanup ve resource handling
4. **Documentation**: Signal flow ve protocol documentation
5. **Testing**: Edge cases ve stress testing

#### 🔍 **Debugging Tips:**
- **Signal Tracing**: `strace` ile signal monitoring
- **Process Monitoring**: `ps`, `top` ile process tracking  
- **Log Analysis**: Debug output ile signal flow tracking
- **Timing Analysis**: Signal delivery timing measurement

### 🧰 **Geliştirme Araçları**

#### 📊 **Monitoring Tools:**
```bash
# Signal monitoring
strace -e trace=kill,signal ./client [PID] "message"

# Process monitoring
ps -ef | grep server
ps -ef | grep client

# System resource usage
top -p [SERVER_PID]
htop
```

#### 🔬 **Debug Commands:**
```bash
# Signal sending test
kill -SIGUSR1 [PID]
kill -SIGUSR2 [PID]

# Process existence check
kill -0 [PID] && echo "Process exists" || echo "Process not found"

# Memory analysis
valgrind --tool=memcheck ./server &
valgrind --tool=memcheck ./client [PID] "test"
```

---

## 🏆 Proje Başarıları

<div align="center">

![Score](https://img.shields.io/badge/Score-125%2F100-gold?style=for-the-badge)
![Tests](https://img.shields.io/badge/Tests-All%20Passed-success?style=for-the-badge)
![Norminette](https://img.shields.io/badge/Norminette-OK-brightgreen?style=for-the-badge)
![Bonus](https://img.shields.io/badge/Bonus-Completed-orange?style=for-the-badge)

### 📊 **Proje İstatistikleri**

| Metrik | Değer |
|--------|-------|
| **Source Files** | 10 |
| **Functions** | 15+ |
| **Signal Types** | 2 (SIGUSR1, SIGUSR2) |
| **Encoding Efficiency** | 8 signals/character |
| **Test Cases** | 25+ |
| **Memory Leak Tests** | ✅ Valgrind Clean |
| **Concurrent Clients** | ✅ Multiple Support |

</div>



---

<div align="center">

### 🎯 **Core Skills Gained**

![Signal Processing](https://img.shields.io/badge/Signal-Processing-blue?style=flat-square)
![IPC](https://img.shields.io/badge/Inter--Process-Communication-green?style=flat-square)
![Binary Encoding](https://img.shields.io/badge/Binary-Encoding-orange?style=flat-square)
![System Programming](https://img.shields.io/badge/System-Programming-red?style=flat-square)
![Concurrency](https://img.shields.io/badge/Concurrency-purple?style=flat-square)

---

**📡 "Minitalk teaches that even the simplest communication requires careful protocol design."**

*Bu proje, sistem seviyesinde programlamanın inceliklerini öğretirken, süreçler arası iletişimin gücünü ve karmaşıklığını gösterir.*

---

### 👨‍💻 Created by Sude Naz Karayıldırım

[![42 Profile](https://img.shields.io/badge/42%20Profile-skarayil-black?style=flat-square&logo=42&logoColor=white)](https://profile.intra.42.fr/users/skarayil)
[![GitHub](https://img.shields.io/badge/GitHub-skarayil-181717?style=flat-square&logo=github&logoColor=white)](https://github.com/skarayil)

**⭐ Eğer bu proje işinize yaradıysa, repo'ya star vermeyi unutmayın!**

</div>
