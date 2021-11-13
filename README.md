## Kernel Sim

### Instalación

#### Preparación

Para configurar el entorno de trabajo es necesario la instalación de las siguientes herramientas.

- cmake
- gcc
- git (para clonar el repositorio)

Estas herramientas pueden ser instaladas de la siguiente manera (Ubuntu): 
```
$ sudo apt install build-essential cmake
```

#### Clonar el repositiorio

```
$ git clone https://github.com/Asiern/kernel-sim.git
```

#### Configuración

Configurar el entorno de trabajo mediante script (recomendado):

```
$ python3 configure.sh -b [BUILD_TYPE]
```

Configurar el entorno de trabajo sin usar scripts:

```
$ cmake -B /build -DCMAKE_BUILD_TYPE=[BUILD_TYPE]
```

*BUILD_TYPE*:

El valor de este parámetro determina la configuración que se utilizará a la hora de compilar.

- `DEBUG:` añade flags para habilitar el debugger `-g`.
- `RELEASE:` añade flags como `-Werror` para que no sea posible compilar con warnings.

### Compilación

Una vez configurado el entorno de trabajo y seleccionado el `BUILD_TYPE`, el proyecto se puede compilar con el siguiente comando.
```
$ cd build && make
```

### Estrucura del codigo fuente

| Directorio | Descripción                                                                                                                      |
| ---------- | -------------------------------------------------------------------------------------------------------------------------------- |
| /src       | Contiene el código fuente                                                                                                        |
| /include   | Contiene los archivos de cabezera                                                                                                |
| /build     | Directorio destino para los archivos compilados (Esta carpeta se crea automáticamente cuando se configura el entorno de trabajo) |
| /.github   | Contiene las configuraciones del repositorio de GitHub                                                                           |


