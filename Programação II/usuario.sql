-- Table: public.usuario

-- DROP TABLE IF EXISTS public.usuario;

CREATE TABLE IF NOT EXISTS public.usuario
(
    nome text COLLATE pg_catalog."default" NOT NULL,
    senha text COLLATE pg_catalog."default" NOT NULL,
    email text COLLATE pg_catalog."default" NOT NULL,
    telefone text COLLATE pg_catalog."default",
    cpf text COLLATE pg_catalog."default" NOT NULL,
    id_usuario integer NOT NULL,
    CONSTRAINT usuario_pkey PRIMARY KEY (id_usuario)
)

TABLESPACE pg_default;

ALTER TABLE IF EXISTS public.usuario
    OWNER to postgres;
