public static class SeedData
{
    public static List<Usuario> Usuarios { get; set; } = new();
    public static List<Empresa> Empresas { get; set; } = new();
    public static List<Doacao> Doacoes { get; set; } = new();
    public static List<Campanha> Campanhas { get; set; } = new();

    public static void Initialize()
    {
        // Campanhas base
        if (Campanhas.Count == 0)
        {
            Campanhas = new List<Campanha>
        {
            new Campanha { Id = 1, Nome = "Materiais Pedagógicos", Meta = "Compra de materiais pedagógicos", ValorMeta = 2000, Arrecadado = 0 },
            new Campanha { Id = 2, Nome = "Reforma da Sala de Terapia", Meta = "Reforma da sala de terapia", ValorMeta = 10000, Arrecadado = 0 }
        };
        }

        // Doações de exemplo
        if (Doacoes.Count == 0)
        {
            Doacoes = new List<Doacao>
        {
            new Doacao { Id = 1, Valor = 500,  Data = DateTime.Now.AddDays(-5), Recorrente = false, Campanha = "Materiais Pedagógicos" },
            new Doacao { Id = 2, Valor = 300,  Data = DateTime.Now.AddDays(-4), Recorrente = true,  Campanha = "Materiais Pedagógicos" },
            new Doacao { Id = 3, Valor = 450,  Data = DateTime.Now.AddDays(-3), Recorrente = false, Campanha = "Materiais Pedagógicos" },
            new Doacao { Id = 4, Valor = 2000, Data = DateTime.Now.AddDays(-2), Recorrente = false, Campanha = "Reforma da Sala de Terapia" },
            new Doacao { Id = 5, Valor = 750,  Data = DateTime.Now.AddDays(-1), Recorrente = true,  Campanha = "Reforma da Sala de Terapia" }
        };
        }

        // Sincroniza o valor arrecadado das campanhas com as doações
        SyncCampanhasArrecadado();

        // Usuários e Empresas
        if (Usuarios.Count == 0)
        {
            Usuarios.Add(new Usuario { Id = 1, Nome = "Maria Silva", Email = "maria@email.com", Telefone = "(11) 99999-9999" });
        }

        if (Empresas.Count == 0)
        {
            Empresas.Add(new Empresa { Id = 1, Nome = "Empresa XYZ Ltda", Cnpj = "12.345.678/0001-90", Email = "contato@xyz.com", ValorParceria = 500 });
        }
    }

    public static void SyncCampanhasArrecadado()
    {
        foreach (var campanha in Campanhas)
        {
            campanha.Arrecadado = Doacoes
                .Where(d => d.Campanha == campanha.Nome)
                .Sum(d => d.Valor);
        }
    }
}