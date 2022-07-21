from setuptools import setup, find_packages

with open("README.md", "r") as fh:
    long_description = fh.read()

setup(
    name="inter_proc_com",
    author="Lucas Braga",
    author_email="lucascmf.braga@gmail.com",
    version="0.0.1",
    description="The lib ables the comunication inter process via socket",
    long_description=long_description,
    long_description_content_type=" text/markdown",
    keywords="Inter, processs",
    license="MIT",

    install_requires=[
        'dynaconf==3.1.4',
    ],
    package_data={"": ["*.csv", "*.toml", "*.json"]},
    packages=find_packages(include="inter_proc_server"),
    include_package_data=True,
    setup_requires=['wheel'],
)
