CREATE TABLE [dbo].[comanda]
(
	[Id_comanda] INT NOT NULL PRIMARY KEY, 
    [data] SMALLDATETIME NULL, 
    [id_client] INT NULL, 
    [locatie] NVARCHAR(50) NULL, 
    [descriere] NVARCHAR(50) NULL
)
